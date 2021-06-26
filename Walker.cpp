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
    ev3api::Motor& rightWheel,
    AdvancedSteering& steering)
    :leftWheel(leftWheel), rightWheel(rightWheel), mSteering(steering)
{
        this->forward = 0;
        this->turn = 0;
        mRunningDistance = new RunningDistance(&leftWheel,&rightWheel);
}

bool Walker::isGoal(){
    return this->mRunningDistance->getRunDistance(); //ゴールまでの距離を比較する
}
void Walker::stop(){
    leftWheel.stop();
    rightWheel.stop();
}
void Walker::run(){
    // 左右モーターに回転を指示する
    
    mSteering.setPower(forward, turn);
}

void Walker::init(){
    leftWheel.reset();
    rightWheel.reset();
}

void Walker::setCommand(
    int forward,int turn){
        this->forward = forward;
        this->turn = turn;
}

void Walker::setTurn(int turn){
    this->turn = turn;
}