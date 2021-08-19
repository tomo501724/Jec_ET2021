#pragma once

#include "LineTracer.h"
#include "Walker.h"
#include "Scenario.h"
#include "SimpleTimer.h"
#include "WallMonitor.h"

class ScenarioTracer
{
private:
    enum State
    {
        UNDEFINED,
        INITIAL,
        WALKING,
        TURNING
    };
    State mState;
    Walker* mWalker;
    Scenario* mScenario;
    SimpleTimer* mSimpleTimer;
    WallMonitor* mWallMonitor;

    bool mIsInitialized;

    int lCount, rCount;

    void initAction();
    /*
    void setCommand(SceneCommands command);
    void setScenario(Scenario* scenario);
    void modeChangeAction();

    void execUndefined();
    void execInitial();
    void execWalking();
    */
    void execGoStraight();
    void execTurnRight();
    void execTurnLeft();

public:
    ScenarioTracer(Walker* walker, SimpleTimer* simpleTimer, WallMonitor* wallMonitor, Scenario* scenario);
    void run();
};
