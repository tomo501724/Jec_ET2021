#pragma once

#include "LineTracer.h"
#include "Walker.h"
#include  "Scenario.h"
#include "SimpleTimer.h"

class ScenarioTracer
{
private:
    enum State
    {
        UNDEFINED,
        INITIAL,
        WALKING
    };
    State mState;
    Walker mWalker;
    Scenario mScenario;
    SimpleTimer mSimpleTimer;

    void initAction();
    void setCommand();
    void modeChangeAction();

    void execUndefined();
    void execInitial();
    void execWalking();

public:
    ScenarioTracer();
    void run();
};