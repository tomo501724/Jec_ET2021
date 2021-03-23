/**
 ******************************************************************************
 ** ファイル名 : LinetraceScenario.h
 ** クラス名   : LinetraceScenario
 **
 ** 概要 : ライントレース走行情報を格納するクラス
 ** 継承元
 ** ファイル名 : Scenario.h
 ** クラス名   : Scenario
 ******************************************************************************
 **/
#pragma once

#include "Scenario.h"

class LinetraceScenario : public Scenario {
protected:
    float kp;       /* 係数P */
    float ki;       /* 係数I */
    float kd;       /* 係数D */
    float krgb;     /* RGB補正値 */

public:
    LinetraceScenario(int dis, int forward, float kp, float ki, float kd, float krgb);
    float getKp();
    float getKi();
    float getKd();
    float getKrgb();
};