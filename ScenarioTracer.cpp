#include "ScenarioTracer.h"

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
//シナリオとレーサーの振る舞いの実装
void ScenarioTracer::modeChangeAction(){
    mScenario->next();
    SceneCommands command = mScenario->currentSceneCommand();
    setCommand(command);

    mSimpleTimer->setTime(mScenario->currentSceneTime());
    mSimpleTimer->start();
}
//UNDEFINEDの処理
void ScenarioTracer::execUndefined()
{
    mState = INITIAL;
}
//INITIALの処理
void ScenarioTracer::execInitial()
{
    initAction();
    mState = WALKING;
    modeChangeAction();
}
//WALKINGの処理
void ScenarioTracer::execWalking()
{
    mWalker->run();
    if (mSimpleTimer->isTimedOut()){
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