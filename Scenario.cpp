#include "Scenario.h"

Scenario::Scenario(Scene* scene) : mTopScene(scene), mCurrentScene(scene) {
    this->mTopScene = scene;
    this->mCurrentScene = scene;
}

bool Scenario::next() {
    mCurrentScene++;
    if (currentSceneCommand() == END) {
        return false;
    } else {
        return true;
    }

}

SceneCommands Scenario::currentSceneCommand() const {
    return mCurrentScene->command;
}

uint32_t Scenario::currentSceneTime() const {
    return (mCurrentScene == 0) ? 0 : mCurrentScene->time;
}

float Scenario::currentSceneSpeed(){
    return mCurrentScene->speed;
}
float Scenario::currentSceneKp(){
    return mCurrentScene->kp;
}
float Scenario::currentSceneKi(){
    return mCurrentScene->ki;
}
float Scenario::currentSceneKd(){
    return mCurrentScene->kd;
}

int Scenario::currentSceneDistance() {
    return mCurrentScene->distance;
}