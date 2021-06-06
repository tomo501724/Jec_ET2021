//ETロボコン練習資料  Chapter4
//とりあえず、PDFのとおりに書いてみようかな

#include "Walker.h"

const int Walker::LOW    = 30;
const int Walker::NORMAL = 50;
const int Walker::HIGH   = 70;
const int Walker::RIGHT  = 0;
const int Walker::LEFT   = 1;

Walker::Walker(
    ev3api::Motor& leftWheel,
    ev3api::Motor& rightWheel)
    :leftWheel(leftWheel), rightWheel(rightWheel)
{
        this->forward = LOW;
        this->turn = RIGHT;
}

void Walker::run(){
    // 左右モーターに回転を指示する
    int  rightPWM = 0,leftPWM = 0;

    if(turn == RIGHT){
        rightPWM = 0;
        leftPWM = forward;
    }else if(turn == LEFT){
        rightPWM = forward;
        leftPWM = 0;
    }else{
        rightPWM = forward;
        leftPWM = forward;
    }

    rightWheel.setPWM(rightPWM);
    leftWheel.setPWM(leftPWM);
}

void Walker::init(){
    leftWheel.reset();
    rightWheel.reset();
}

void Walker::setCommand(
    int forward,int turn){
        this->forward=forward;
        this->turn=turn;
}

