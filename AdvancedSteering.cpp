/**
 ******************************************************************************
 ** ファイル名 : AdvancedSteering.cpp
 ** クラス名   : AdvancedSteering
 **
 ** 概要 : 改良型ステアリング制御の計算を行うクラス
 ******************************************************************************
 **/
#include "AdvancedSteering.h"

/**
 * Motor& leftMotor     : 左モータ
 * Motor& rightMotor    : 右モータ
 */
AdvancedSteering::AdvancedSteering(ev3api::Motor& leftMotor, ev3api::Motor& rightMotor) 
: mLeftMotor(leftMotor), mRightMotor(rightMotor) 
{}

/**
 * 出力、旋回率指定
 * int power        : -100 ~ 100
 * int turnRatio    : -50 ~ 50
 */
void AdvancedSteering::setPower(int power, int turnRatio) {
    int leftPower, rightPower;

    //旋回率は(-50 ~ 50)
    
    if (turnRatio > 100)
    {
        turnRatio = 100;
    }
    else if (turnRatio < -100)
    {
        turnRatio = -100;
    }
    
    //左右出力を旋回率分増減
    leftPower = (int)(power - power * (-turnRatio * 0.01));
    rightPower = (int)(power - power * (turnRatio * 0.01));
    
    //モータ出力(-100 ~ 100)
    if (leftPower > 100) 
    {
        leftPower  = 100;
        rightPower -= leftPower - 100;
    } 
    else if (leftPower < -100)
    {
        leftPower  = -100;
        rightPower -= leftPower + 100;
    }
    else if (rightPower > 100)
    {
        rightPower  = 100;
        leftPower -= rightPower - 100;
    }
    else if (rightPower < -100)
    {
        rightPower  = -100;
        leftPower -= rightPower + 100;
    }
       
    mLeftMotor.setPWM(leftPower);
    mRightMotor.setPWM(rightPower);
}