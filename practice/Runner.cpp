#include "Runner.h"

//現在のC/C++コンパイラは #pragma once の一文でもインクルードガードできます

Runner::Runner(
    ev3api::Motor* leftMotor
    ,ev3api::Motor* rightMotor
    ,int speed){

    this->leftMotor = leftMotor;
    this->rightMotor = rightMotor;

    setSpeed(speed);
}

void Runner::forward(){
    leftMotor->setPWM(speed);
    rightMotor->setPWM(speed);
}
void Runner::back(){
    leftMotor->setPWM(-speed);
    rightMotor->setPWM(-speed);

}
void Runner::turnLeft(){
    leftMotor->stop();
    rightMotor->setPWM(speed);
}
void Runner::turnRight(){
    leftMotor->setPWM(speed);
    rightMotor->stop();
}
void Runner::stop(){
    leftMotor->stop();
    rightMotor->stop();
}

void Runner::setSpeed(int speed){
    if (speed < 0)
    {
        speed = 0;
    }
    else if (speed > ev3api::Motor::PWM_MAX)
    {
        speed = ev3api::Motor::PWM_MAX;
    }
    this->speed = speed;
}
int Runner::getSpeed(){
    return speed;
}