/**
 ******************************************************************************
 ** ファイル名 : Run.h
 ** クラス名   : Run
 **
 ** 概要 : 走行を管理するクラス
 ******************************************************************************
 **/
#pragma once

#include "ev3api.h"
#include "Tripmeter.h"
#include "Clock.h"
#include "Steering.h"
#include "TouchSensor.h"

class Run
{
protected:
    ev3api::Motor*          leftMotor;
    ev3api::Motor*          rightMotor;
    ev3api::Steering*       steering;
    Tripmeter*              tripmeter;
    ev3api::Clock*          clock;
    ev3api::TouchSensor*    touchSensor;

    int scenarioNumber = 0; //シナリオナンバー

public:
    Run(int course);
    virtual ~Run();
    virtual void running() = 0;
    virtual void stop() = 0;
    virtual void startWait() = 0;

};