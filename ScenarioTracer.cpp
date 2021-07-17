#include "ScenarioTracer.h"
#include "Walker.h"

ScenarioTracer::ScenarioTracer(Walker* walker, SimpleTimer* simpleTimer, WallMonitor* wallMonitor) {
    mWalker = walker;
    mSimpleTimer = simpleTimer;
    mWallMonitor = wallMonitor;
}

void ScenarioTracer::initAction(){
    mWalker->init();
}
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
    Scene* scene = mScenario->next();
    SceneCommands command = mScenario->currentSceneCommand();
    setCommand(command);
    int range = mWallMonitor->isInRange();
    mWallMonitor->setRange();
    mWalker->setForword(scene->speed)

    

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

void ScenarioTracer::run(){
    switch(mState){
        case UNDEFINED:
            execUndefined();
            break;
        case INITIAL:
            execInitial();
            break;
        case WALKING:
            execWalking();
            break;
        default:
            break;
    }
}