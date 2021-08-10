#include "ScenarioTracer.h"
#include "Walker.h"
#include "SceneCommands.h"

ScenarioTracer::ScenarioTracer(Walker* walker, SimpleTimer* simpleTimer, WallMonitor* wallMonitor, Scenario* scenario) {
    mWalker = walker;
    mSimpleTimer = simpleTimer;
    mScenario = scenario;
    mWallMonitor = wallMonitor;
}

void ScenarioTracer::initAction(){
    mWalker->init();
}
/*
void ScenarioTracer::setCommand(SceneCommands command){
    int turn = 0;
    if (command == TURN_LEFT){
        turn = Walker::LEFT;
    } else if(command == TURN_RIGHT){
        turn = Walker::RIGHT;
    }
    mWalker->setCommand(Walker::LOW,turn);
}

void ScenarioTracer::setScenario(Scenario* scenario) {
    mScenario = scenario;
}

//シナリオトレーサーの振る舞いの実装
void ScenarioTracer::modeChangeAction(){
    bool hasNext = mScenario->next();
    if (hasNext)
    {
        SceneCommands command = mScenario->currentSceneCommand();
        setCommand(command);
        int range = mWallMonitor->isInRange();
        mWallMonitor->setRange(range);
        mWalker->setForward(mScenario->currentSceneSpeed());
    }
    
    

    

    //mSimpleTimer->setTime(mScenario->currentSceneTime());
    //mSimpleTimer->start();
}
//UNDEFINEDの処理
void ScenarioTracer::execUndefined()
{
    mState = ScenarioTracer::INITIAL;
}
//INITIALの処理
void ScenarioTracer::execInitial()
{
    initAction();
    mState = ScenarioTracer::WALKING;
    modeChangeAction();
}
//WALKINGの処理
void ScenarioTracer::execWalking()
{
    mWalker->run();
    if (mSimpleTimer->isTimeOut()){
        mSimpleTimer->stop();
        modeChangeAction();
    }
}
*/
void ScenarioTracer::execGoStraight()
{
    if (mWalker->getDistance() > mScenario->currentSceneDistance())
    {

        syslog(LOG_NOTICE, "Change Scenario\n walker: %d\n scenario: %d", mWalker->getDistance(), mScenario->currentSceneDistance());

        mScenario->next();
        return;
    }
    
    mWalker->setCommand(mScenario->currentSceneSpeed(), 0);
}

void ScenarioTracer::execTurnLeft()
{

}

void ScenarioTracer::execTurnRight()
{

}

void ScenarioTracer::run(){
    switch(mScenario->currentSceneCommand()){
        /*
        case UNDEFINED:
            execUndefined();
            break;
        case INITIAL:
            execInitial();
            break;
        case WALKING:
            execWalking();
            break;
        */
        case GO_STRAIGHT:
            execGoStraight();
            break;
        case TURN_LEFT:
            execTurnLeft();
            break;
        case TURN_RIGHT:
            execTurnRight();
            break;
        default:
            break;
    }
}