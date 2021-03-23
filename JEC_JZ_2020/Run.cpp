/**
 ******************************************************************************
 ** ファイル名 : Run.cpp
 ** クラス名   : Run
 **
 ** 概要 : 走行を管理するクラス
 ******************************************************************************
 **/
#include "Run.h"

/**
 * コンストラクタ
 */
Run::Run(int course) {
    leftMotor   = new ev3api::Motor(PORT_C);
    rightMotor  = new ev3api::Motor(PORT_B);

    if (course)
    {
        steering    = new ev3api::Steering(*rightMotor, *leftMotor);
    }
    else 
    {
        steering    = new ev3api::Steering(*leftMotor, *rightMotor);  
    }

    tripmeter   = new Tripmeter(leftMotor, rightMotor);
    clock       = new ev3api::Clock();
    touchSensor = new ev3api::TouchSensor(PORT_1);
}

/**
 * デストラクタ
 */
Run::~Run() {
    delete leftMotor;
    delete rightMotor;
    delete steering;
    delete tripmeter;
    delete clock;
    delete touchSensor;
}
