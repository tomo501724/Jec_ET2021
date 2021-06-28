#include "Scenario.h"

Scenario::Scenario(Scene* scene) : mTopScene(scene), mCurrentScene(scene) {
    this->mTopScene = scene;
    this->mCurrentScene = scene;
}

void Scenario::add(Scene* scene) {
    if (mTopScene == 0) {
        mTopScene = scene;
    } else {
        Scene* s = mTopScene;
        while(s->next != top()) {
            s = s->next;
        }
        s->next = scene;
    }
    scene->next = top();
}

Scene* Scenario::top() const {
    return mTopScene;
}

Scene* Scenario::current() const {
    return mCurrentScene;
}

Scene* Scenario::next() {
    if (mCurrentScene != 0) {
        mCurrentScene = mCurrentScene->next;
    } else {
        mCurrentScene = mTopScene;
    }
    return mCurrentScene;
}

SceneCommands Scenario::currentSceneCommand() const {
    return (mCurrentScene == 0) ? GO_STRAIGHT : mCurrentScene->command;
}

uint32_t Scenario::currentSceneTime() const {
    return (mCurrentScene == 0) ? 0 : mCurrentScene->time;
}

float currentSceneSpeed(){
    return mCurrnetScene->speed;
}
float currentSceneKp(){
    return mCurrentScene->kp;
}
float currentSceneKi(){
    return mCurrentScene->ki;
}
float currentSceneKd(){
    return mCurrnetScene->kd;
}