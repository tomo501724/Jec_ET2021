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

class LineTracer {
public:
    LineTracer(LineMonitor* lineMonitor,
               Walker* walker);
    ~LineTracer();

    void run();

private:
    LineMonitor* mLineMonitor;
    Walker* mWalker;
    bool mIsInitialized;
    PID* mPID;
    ev3api::TouchSensor* mTouchSensor; 
    int mTargetRGB;
    

    int calcDirection(bool isOnLine);
};

#endif  // EV3_APP_LINETRACER_H_
