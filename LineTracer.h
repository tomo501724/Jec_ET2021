/******************************************************************************
 *  LineTracer.h (for LEGO Mindstorms EV3)
 *  Created on: 2015/01/25
 *  Definition of the Class LineTracer
 *  Author: Kazuhiro Kawachi
 *  Copyright (c) 2015 Embedded Technology Software Design Robot Contest
 *****************************************************************************/

#ifndef EV3_APP_LINETRACER_H_
#define EV3_APP_LINETRACER_H_

#include "LineMonitor.h"
#include "Walker.h"
#include "PID.h"
#include "TouchSensor.h"
#include "Scenario.h"
#include "SimpleTimer.h"

class LineTracer {
private:
    LineMonitor* mLineMonitor;
    Walker* mWalker;
    Scenario* mScenario;
    SimpleTimer* mTimer;
    bool mIsInitialized;
    PID* mPID;
    ev3api::TouchSensor* mTouchSensor; 
    int mTargetRGB, mTargetBlueRGB, mBlueRGB;

public:
    LineTracer(LineMonitor* lineMonitor,
               Walker* walker,
               Scenario* scenario,
               SimpleTimer* timer);
    ~LineTracer();

    void run();
    int calcDirection(bool isOnLine);
    bool isGoal();

    int getDistance();
    void setCommand(float kp, float ki, float kd, int power);

    void execLineTrace();
    void execLineTraceUntilBlue();
    void execLineTraceOnBlue();
    void execLineTraceUntilTime();
};

#endif  // EV3_APP_LINETRACER_H_
