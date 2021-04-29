/**
 ******************************************************************************
 ** ファイル名 : AdvancedSteering.h
 ** クラス名   : AdvancedSteering
 **
 ** 概要 : 改良型ステアリング制御の計算を行うクラス
 ******************************************************************************
 **/
#pragma once

#include "Motor.h"
#include "ev3api.h"

class AdvancedSteering
{
private:
    ev3api::Motor& mLeftMotor;
    ev3api::Motor& mRightMotor;

public:
    AdvancedSteering(ev3api::Motor& leftMotor, ev3api::Motor& rightMotor);
    void setPower(int power, int turnRatio);
};