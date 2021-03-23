/**
 ******************************************************************************
 ** ファイル名 : Tripmeter.h
 ** クラス名   : Tripmeter
 **
 ** 概要 : 区間距離の計算を行うクラス
 **
 ** 継承元
 ** ファイル名 : RunningDistance.h
 ** クラス名   : RunningDistance
 ******************************************************************************
 **/
#pragma once

#include "RunningDistance.h"

class Tripmeter : public RunningDistance 
{
public:
    Tripmeter(ev3api::Motor* leftM, ev3api::Motor* rightM);
    void resetDistance();
};