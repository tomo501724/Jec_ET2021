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
                       Scenario* scenario)
    : mLineMonitor(lineMonitor),
      mWalker(walker),
      mScenario(scenario),
      mIsInitialized(false) 
{
    mPID = new PID(0.7f,  0.0f, 103.0f);
    mTouchSensor = new ev3api::TouchSensor(PORT_1);
    mTargetRGB = 97;
    
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
    //mWalker->setCommand(mScenario->currentSceneSpeed(), turn);
    mWalker->setCommand(100, turn);
    // 走行を行う
    mWalker->run();
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
    mWalker->setForward(power);
}

int LineTracer::getDistance(){
    return mWalker->getDistance();
}