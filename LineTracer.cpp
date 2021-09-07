/******************************************************************************
 *  LineTracer.cpp (for LEGO Mindstorms EV3)
 *  Created on: 2015/01/26
 *  Implementation of the Class LineTracer
 *  Author: Kazuhiro Kawachi
 *  Copyright (c) 2015 Embedded Technology Software Design Robot Contest
 *****************************************************************************/

#include "LineTracer.h"

/**
 * コンストラクタ
 * @param lineMonitor     ライン判定
 * @param walker 走行
 */
LineTracer::LineTracer(LineMonitor* lineMonitor,
                       Walker* walker,
                       Scenario* scenario,
                       SimpleTimer* timer)
    : mLineMonitor(lineMonitor),
      mWalker(walker),
      mScenario(scenario),
      mTimer(timer),
      mIsInitialized(false)
{
    mPID = new PID(0.7f,  0.0f, 103.0f);
    mTouchSensor = new ev3api::TouchSensor(PORT_1);
    //mTargetRGB = 97;
    mTargetRGB = 198;
    mTargetBlueRGB = 246;
    mBlueRGB = 198;
}

LineTracer::~LineTracer() {
    delete mPID;
    delete mTouchSensor;
}

/**
 * ライントレースする
 */
void LineTracer::run() {
    if (mIsInitialized == false) {
        mWalker->init();
        mIsInitialized = true;
    }

    switch (mScenario->currentSceneCommand())
    {
    case LINE_TRACE:
        execLineTrace();
        break;
    
    case LINE_TRACE_UNTIL_BLUE:
        execLineTraceUntilBlue();
        break;

    case LINE_TRACE_ON_BLUE:
        execLineTraceOnBlue();
        break;

    case LINE_TRACE_UNTIL_TIME:
        execLineTraceUntilTime();
        break;

    default:
        break;
    }
}

/**
 * 走行体の向きを計算する
 * @param isOnLine true:ライン上/false:ライン外
 * @retval RIGHT  ライン上にある場合(右旋回指示)
 * @retval LEFT ライン外にある場合(左旋回指示)
 */
int LineTracer::calcDirection(bool isOnLine) {
    if (isOnLine) {
        // ライン上にある場合
        return Walker::RIGHT;
    } else {
        // ライン外にある場合
        return Walker::LEFT;
    }
}

bool LineTracer::isGoal() {
    return mWalker->getDistance() < mScenario->currentSceneDistance();

}

void LineTracer::setCommand(float kp, float ki, float kd, int power){
    mPID->setPID(kp, ki, kd);
    mWalker->setForward(100); //一時的にpoewrを100にしたり
}

int LineTracer::getDistance(){
    return mWalker->getDistance();
}

void LineTracer::execLineTrace() {
    if (mWalker->getDistance() > mScenario->currentSceneDistance())
    {

        mWalker->resetDistance();
        mScenario->next();
        return;
    }
    
    mPID->setPID(mScenario->currentSceneKp(),
                 mScenario->currentSceneKi(),
                 mScenario->currentSceneKd());

    // 走行体の向きを計算する
    int turn = mPID->calcControl(mTargetRGB - mLineMonitor->getRGB());
    mWalker->setCommand(mScenario->currentSceneSpeed(), turn);
    // 走行を行う
    mWalker->run();
}

void LineTracer::execLineTraceUntilBlue() {
    if (mLineMonitor->isOnBlue()) {
        mScenario->next();
        mWalker->resetDistance();
    }
    else
    {
        execLineTrace();
    }
}

void LineTracer::execLineTraceOnBlue() {
    if (mWalker->getDistance() > mScenario->currentSceneDistance())
    {

        mWalker->resetDistance();
        mScenario->next();
        return;
    }
    
    mPID->setPID(mScenario->currentSceneKp(),
                 mScenario->currentSceneKi(),
                 mScenario->currentSceneKd());

    // 走行体の向きを計算する
    int turn = mPID->calcControl(mBlueRGB - mLineMonitor->getRGB());
    mWalker->setCommand(mScenario->currentSceneSpeed(), turn);
    // 走行を行う
    mWalker->run();
}

void LineTracer::execLineTraceUntilTime() {
    if (mTimer->isStarted())
    {
        if (mTimer->isTimeOut())
        {
            mWalker->resetDistance();
            mTimer->stop();
            mScenario->next();
            return;
        }
    }
    else
    {
        mTimer->setTime(mScenario->currentSceneTime());
        mTimer->start();
    }

    execLineTrace();
}