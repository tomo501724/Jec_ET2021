//ETロボコン2021 技術教育資料  Chapter 4より
#pragma once

#include "Motor.h"
#include "AdvancedSteering.h"
#include "RunningDistance.h"
#include "Tripmeter.h"

class Walker
{

private:
    ev3api::Motor &leftWheel, &rightWheel;
    AdvancedSteering& mSteering;
    int forword, turn, LINETRACE_DISTANCE;
    Tripmeter* mRunningDistance;

public:
    static const int LOW, NORMAL, HIGH, RIGHT, LEFT;

    Walker(
        ev3api::Motor& leftWheel,
        ev3api::Motor& rightWheel,
        AdvancedSteering& steering);

    bool isGoal();
    void stop();

    void init();
    void run();
    void setCommand(int forword, int turn);
    void setTurn(int turn);
    int getDistance();
    void setForward(int power);
    void resetDistance();
    int getLeftWheelCount();
    int getRightWheelCount();
    void turnLeft(int power);
    void turnRight(int power);
};