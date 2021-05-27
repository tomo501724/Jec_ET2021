#include "Runner.h"

//現在のC/C++コンパイラは #pragma once の一文でもインクルードガードできます

Runner::Runner(
    ev3api::Motor* leftMotor
    ,ev3api::Motor* rightMotor
    ,int speed){

        this->leftMotor=leftMotor;
        this->rightMotor=rightMotor;

        this->setSpeed(speed);

}

void Runner::forward(){
    this->leftMotor->setPWM(this->speed);
    this->rightMotor->setPWM(this->speed);
}
void Runner::back(){
    this->leftMotor->setPWM(-this->speed);
    this->rightMotor->setPWM(-this->speed);

}
void Runner::turnLeft(){
    this->leftMotor->stop();
    this->rightMotor->setPWM(this->speed);
}
void Runner::turnRight(){
    this->leftMotor->setPWM(this->speed);
    this->rightMotor->stop();
}
void Runner::stop(){
    this->leftMotor->stop();
    this->rightMotor->stop();
}

void Runner::setSpeed(int speed){
    if(speed<0){
        speed=0;
    }else if(speed>ev3api::Motor::PWM_MAX){
        speed=ev3api::Motor::PWM_MAX;
    }
    this->speed=speed;
}
int Runner::getSpeed(){
    return this->speed;
}