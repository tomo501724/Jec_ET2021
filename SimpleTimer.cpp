#include "SimpleTimer.h"

SimpleTimer::SimpleTimer(ev3api::Clock& clock) 
:mClock(clock)
{
    mStartTime = 0;
    mDelayMs = 0;
    mTargetTime = 0;
}

void SimpleTimer::setTime(uint32_t delay) {
    mDelayMs = delay;
}

void SimpleTimer::start() {
    mStartTime = mClock.now();
    mTargetTime = mStartTime + mDelayMs;
}

void SimpleTimer::stop() {
    mStartTime = 0;
    mTargetTime = 0;
}

bool SimpleTimer::isTimeOut() {
    return mTargetTime < mClock.now();
}

bool SimpleTimer::isStarted() {
    return mStartTime != 0;
}