/**
 ******************************************************************************
 ** ファイル名 : LinetraceRun.h
 ** クラス名   : LinetraceRun
 **
 ** 概要 : ライントレース走行を管理するクラス
 **
 ** 継承元
 ** ファイル名 : Run.h
 ** クラス名   : Run
 ******************************************************************************
 **/
#pragma once

#include "Run.h"
#include "PID.h"
#include "Color.h"
#include "LinetraceScenario.h"
#include "Clock.h"
#include "UserInterface.h"

class LinetraceRun : public Run 
{
protected:
    Color* colorSensor;
    PID* pid;

    /**
     * ライントレースシナリオ
     * (走行距離, 走行速度, P値, I値, D値)
     * 個々の値をいじって早く走らせよう
     */
    LinetraceScenario scenario[3] = {
        LinetraceScenario(100, 50, 0.8f, 0.5f, 9.0f),
        LinetraceScenario(90000, 80, 1.1f, 0.9f, 10.0f),
        LinetraceScenario(0, 0, 0.0f, 0.0f, 0.0f)
    };

    UserInterface* ui;

    int colorBlack = 0, colorWhite = 0; //白黒RGB値
    int targetRGB = 0;                  //目標RGB値

public:
    LinetraceRun(int course);
    ~LinetraceRun();
    void running() override;
    void stop() override;
    void startWait() override;
    void btUpdate();
};
