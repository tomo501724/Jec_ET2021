/**
 ******************************************************************************
 ** ファイル名 : NoLinetraceRun.cpp
 ** クラス名   : NoLinetraceRun
 **
 ** 概要 : ライントレースなし走行を管理するクラス
 **
 ** 継承元
 ** ファイル名 : Run.cpp
 ** クラス名   : Run
 ******************************************************************************
 **/
#include "NoLinetraceRun.h"

/**
 * コンストラクタ
 * course           : コース
 * gyroCorrection   : ジャイロセンサ補正値
 */
NoLinetraceRun::NoLinetraceRun(int course, int gyroCorrection)
: Run(course)
{
    gyroSensor = new ev3api::GyroSensor(PORT_4);
    
    if (course == 0)
    {
        this->gyroCorrection = -gyroCorrection;
    }
}

/**
 * デストラクタ
 */
NoLinetraceRun::~NoLinetraceRun() {
    delete gyroSensor;
}

/**
 * 走行
 */
void NoLinetraceRun::running() {
    
    //区間切り替え
    if (scenario[scenarioNumber].getDis() < tripmeter->getRunDistance()) {
        scenarioNumber++;
        syslog(LOG_NOTICE, "SCENARIO NUM : %d", scenarioNumber);
        //終了処理
        if (5 <= scenarioNumber) {
            
            //終了タスクへ
            syslog(LOG_NOTICE, "FINISH");
            act_tsk(EXIT_TASK);
            ext_tsk();
        }

        //走行距離、タイマーリセット
        tripmeter->resetDistance();
        clock->reset();
    }
    //旋回処理
    steering->setPower( scenario[scenarioNumber].getForward(), gyroCorrection - gyroSensor->getAngle());
}

/**
 * 停止
 */
void NoLinetraceRun::stop() {
    steering->setPower(0, 0);
}

/**
 * スタート待機
 */
void NoLinetraceRun::startWait() {
    gyroSensor->reset();
    tripmeter->resetDistance();
    clock->reset();
    
    syslog(LOG_NOTICE, "NOLINETRACE START");
    syslog(LOG_NOTICE, "SCENARIO NUM : %d", scenarioNumber);
    act_tsk(NO_LINETRACE_TASK);
    ext_tsk();
}