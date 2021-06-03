//ETロボコン2021 技術教育資料  Chapter 4より
#pragma once

#include "Motor.h"

class Walker{

    private:
        ev3api::Motor& leftWheel,rightWheel;
        int forward,turn;
    public:
        static const int LOW,NORMAL,HIGH,RIGHT,LEFT;
        
        Walker(
            ev3api::Motor& leftWheel,
            ev3api::Motor& rightWheel);
        void inti();
        void run();
        void setCommand(int forward, int turn);


};