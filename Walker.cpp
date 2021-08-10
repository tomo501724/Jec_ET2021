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
        this->forword = 0;
        this->turn = 0;
        mRunningDistance = new Tripmeter(&leftWheel,&rightWheel);
        LINETRACE_DISTANCE = 5500;
}

bool Walker::isGoal(){
    return LINETRACE_DISTANCE < this->mRunningDistance->getRunDistance(); //ゴールまでの距離を比較する
}
void Walker::stop(){
    leftWheel.stop();
    rightWheel.stop();

    //syslog(LOG_NOTICE ,"[STOP] DISTANCE: %d", mRunningDistance->getRunDistance());
}
void Walker::run(){
    // 左右モーターに回転を指示する
    //syslog(LOG_NOTICE ,"DISTANCE: %d", mRunningDistance->getRunDistance());
    mSteering.setPower(forword, turn);
}

void Walker::init(){
    leftWheel.reset();
    rightWheel.reset();
}

void Walker::setCommand(
    int forword,int turn){
        this->forword = forword;
        this->turn = turn;
}

void Walker::setTurn(int turn){
    this->turn = turn;
}

void Walker::setForward(int power){
    this->forword = power;
}

int Walker::getDistance(){
    return mRunningDistance->getRunDistance();
}