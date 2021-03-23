/**
 ******************************************************************************
 ** ファイル名 : LinetraceRun.cpp
 ** クラス名   : LinetraceRun
 **
 ** 概要 : ライントレース走行を管理するクラス
 **
 ** 継承元
 ** ファイル名 : Run.cpp
 ** クラス名   : Run
 ******************************************************************************
 **/

#include "LinetraceRun.h"

/**
 * コンストラクタ
 */
LinetraceRun::LinetraceRun(int course) 
: Run(course)
{
    colorSensor = new Color(PORT_2);
    pid         = new PID();
    //ui          = new UserInterface();
}

/**
 * デストラクタ
 */
LinetraceRun::~LinetraceRun() {
    delete colorSensor;
    delete pid;
    //delete ui;
}

/**
 * 走行
 */
void LinetraceRun::running() {

    //区間切り替え
    if (scenario[scenarioNumber].getDis() < tripmeter->getRunDistance()) {
        syslog(LOG_NOTICE, "SCENARIO NUM : %d", scenarioNumber);
        scenarioNumber++;
        //終了処理
        if (7 <= scenarioNumber) {

            //ライントレースなし走行初期化タスクへ
            act_tsk(NO_LINETRACE_INIT_TASK);
            ext_tsk();
        }

        //PID値更新
        pid->PID::setPID(scenario[scenarioNumber].getKp(), 
                    scenario[scenarioNumber].getKi(), 
                    scenario[scenarioNumber].getKd()
        );
        
        //走行距離、タイマーリセット
        tripmeter->resetDistance();
        syslog(LOG_NOTICE, "DISTANCE : %d", tripmeter->getRunDistance());
        clock->reset();
    }

    //カラーセンサ更新
    colorSensor->update();
    
    //旋回処理
    steering->setPower( scenario[scenarioNumber].getForward(),
                        pid->calcControl(colorSensor->getTotalRGB() - targetRGB - scenario[scenarioNumber].getKrgb())
    );

    if (touchSensor->isPressed()) {
        syslog(LOG_NOTICE, "DISTANCE : %d", tripmeter->getRunDistance());
    }


}

/**
 * 停止
 */
void LinetraceRun::stop() {
    steering->setPower(0, 0);
}

/**
 * 走行待機
 */
void LinetraceRun::startWait() {
    colorSensor->update();
    
    /* キャリブレーション処理、シュミレータでは使用しない */
    if (ev3_button_is_pressed(LEFT_BUTTON)) {
        
        colorBlack = colorSensor->getTotalRGB();
        targetRGB = (colorBlack + colorWhite) / 2;

        syslog(LOG_NOTICE, "SET COLOR : %d", targetRGB);

    }

    if (ev3_button_is_pressed(RIGHT_BUTTON)) {

        colorWhite = colorSensor->getTotalRGB();
        targetRGB = (colorBlack + colorWhite) / 2;

        syslog(LOG_NOTICE, "SET COLOR : %d", targetRGB);
    }

    //スタート   
    if (ev3_button_is_pressed(ENTER_BUTTON) || touchSensor->isPressed()) {

        //シュミレータ環境用白黒RGB値
        colorBlack = 8;
        colorWhite = 186;
        //青色76
        //目標RGB値
        targetRGB = (colorBlack + colorWhite) / 2;

        //PID値初期設定
        pid->setPID(scenario[scenarioNumber].getKp(), 
                    scenario[scenarioNumber].getKi(), 
                    scenario[scenarioNumber].getKd()
        );
        
        //走行距離、タイマーリセット
        tripmeter->resetDistance();
        clock->reset();

        //ライントレース走行タスク起動、自タスク終了
        syslog(LOG_NOTICE, "LINETRACE START");
        syslog(LOG_NOTICE, "SCENARIO NUM : %d", scenarioNumber);
        act_tsk(LINETRACE_TASK);
        ext_tsk();
    }
}

/**
 * Bluetooth更新（おそらくデバッグ用、使わないかも）
 */
void LinetraceRun::btUpdate() {
    //ui->update();
}