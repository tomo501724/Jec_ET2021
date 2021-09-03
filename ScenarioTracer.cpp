#include "ScenarioTracer.h"
#include "Walker.h"
#include "SceneCommands.h"
#include "SimpleTimer.h"

ScenarioTracer::ScenarioTracer(Walker* walker, SimpleTimer* timer, WallMonitor* wallMonitor, Scenario* scenario) {
    mWalker = walker;
    mScenario = scenario;
    mWallMonitor = wallMonitor;
    mState = UNDEFINED;
    mTimer = timer;
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

        mWalker->resetDistance();
        mScenario->next();
        return;
    }
    
    mWalker->setCommand(mScenario->currentSceneSpeed(), 0);
    mWalker->run();
}

void ScenarioTracer::execGoStraightUntilTime() {
    if (mTimer->isStarted())
    {
        if (mTimer->isTimeOut())
        {
            mWalker->resetDistance();
            mTimer->stop();
            mScenario->next();
            return;
        }
    }
    else
    {
        mTimer->setTime(mScenario->currentSceneTime());
        mTimer->start();
    }
    execGoStraight();
}

void ScenarioTracer::execTurnLeft()
{
    execTurn(-180);
}

void ScenarioTracer::execTurnRight()
{
    execTurn(180);
}

void ScenarioTracer::execTurn(int turn) {
    if (mState != TURNING)
    {
        mState = TURNING;
        lCount = mWalker->getLeftWheelCount() + turn;
        rCount = mWalker->getRightWheelCount() - turn;
    }

    if (mWalker->getLeftWheelCount() >= lCount && mWalker->getRightWheelCount() <= rCount)
    {
        mState = UNDEFINED;
        mWalker->resetDistance();
        mScenario->next();
    }
    
    if (0 < turn) {
        mWalker->turnRight(mScenario->currentSceneSpeed());
    }
    else if (turn < 0) {
        mWalker->turnLeft(mScenario->currentSceneSpeed());
    }
}

void ScenarioTracer::execWallDitecton()
{
    if (mWallMonitor->isInRange(32) || mWalker->getDistance() > mScenario->currentSceneDistance())
    {

        syslog(LOG_NOTICE, "Change Scenario\n walker: %d\n scenario: %d", mWalker->getDistance(), mScenario->currentSceneDistance());

        mWalker->resetDistance();
        mScenario->next();
        return;
    }
    
    mWalker->setCommand(mScenario->currentSceneSpeed(), 0);
    mWalker->run();
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
        case GO_STRAIGHT_UNTIL_TIME:
            execGoStraightUntilTime();
            break;
        case TURN_LEFT:
            execTurnLeft();
            break;
        case TURN_RIGHT:
            execTurnRight();
            break;
        case TURN:
            execTurn(mScenario->currentSceneDistance());
            break;
        case WALL_DETECTION:
            execWallDitecton();
            break;
        default:
            break;
    }
}