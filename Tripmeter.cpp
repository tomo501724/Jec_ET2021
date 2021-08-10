/**
 ******************************************************************************
 ** ファイル名 : Tripmeter.cpp
 ** クラス名   : Tripmeter
 **
 ** 概要 : 区間距離の計算を行うクラス
 **
 ** 継承元
 ** ファイル名 : RunningDistance.cpp
 ** クラス名   : RunningDistance
 ******************************************************************************
 **/
#include "Tripmeter.h"

Tripmeter::Tripmeter(ev3api::Motor* leftM, ev3api::Motor* rightM)
    : RunningDistance(leftM, rightM)
{}

void Tripmeter::resetDistance() {
    leftMotor->setCount(0);
    rightMotor->setCount(0);
}