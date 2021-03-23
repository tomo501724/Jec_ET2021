/**
 ******************************************************************************
 ** ファイル名 : NoLinetraceRun.h
 ** クラス名   : NoLinetraceRun
 **
 ** 概要 : ライントレースなし走行を管理するクラス
 **
 ** 継承元
 ** ファイル名 : Run.h
 ** クラス名   : Run
 ******************************************************************************
 **/
#pragma once

#include "ev3api.h"
#include "GyroSensor.h"
#include "Sensor.h"
#include "Scenario.h"
#include "Run.h"

class NoLinetraceRun : public Run 
{
protected:
    ev3api::GyroSensor* gyroSensor;
    Scenario scenario[5] = {
        Scenario(100, 10),
        Scenario(200, 25),
        Scenario(900, 50),
        Scenario(100, 25),
        Scenario(120, 10)
    };

    int gyroCorrection; /* ジャイロ補正値 */

public:
    NoLinetraceRun(int course, int gyroCorrection);
    ~NoLinetraceRun();
    void running() override;
    void stop() override;
    void startWait() override;
};