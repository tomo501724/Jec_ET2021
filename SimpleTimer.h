#pragma once

#include "ev3api.h"
#include "Clock.h"

class SimpleTimer
{
private:
    ev3api::Clock* mClock;
    uint32_t mDelayMs;
    uint32_t mStartTime;
    uint32_t mTargetTime;
public:
    SimpleTimer(ev3api::Clock* clock);
    void setTime(uint32_t delay);
    void start();
    void stop();
    bool isTimeOut();
    bool isStarted();
};
