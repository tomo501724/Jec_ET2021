#ifndef __RUNNER_H__

#define __RUNNER_H__

#include "ev3api.h"
#include "Motor.h"

class Runner{
    private:
        ev3api::Motor* leftMotor;
        ev3api::Motor* rightMotor;
        int speed;
    public:
        Runner(
            ev3api::Motor* leftMotor
            ,ev3api::Motor* rightMotor
            ,int speed);
        
        void forward();
        void back();
        void turnLeft();
        void turnRight();
        void stop();

        void setSpeed(int speed);
        int getSpeed();
};

#endif