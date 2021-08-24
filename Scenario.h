#pragma once

#include "ev3api.h"
#include "Scene.h"

class Scenario {
private:
    Scene* mTopScene;
    Scene* mCurrentScene;
    Scene scenes[8] = {
        {LINE_TRACE, 0, 6770, 100, 0.9f,  0.0f, 103.0f},
        {GO_STRAIGHT, 0, 290, 40, 0.0f,  0.0f, 0.0f},
        {LINE_TRACE, 0, 790, 20, 0.9f,  0.0f, 103.0f},
        {GO_STRAIGHT, 0, 190, 40, 0.0f,  0.0f, 0.0f},
        {LINE_TRACE, 0, 340, 20, 0.9f,  0.0f, 103.0f},
        {GO_STRAIGHT, 0, 50, 40, 0.0f, 0.0f, 0.0f},
        {LINE_TRACE, 0, 460, 20, 0.9f, 0.0f, 103.0f},
        {END, 0, 0, 0, 0.0f, 0.0f, 0.0f}
    };

public:
    explicit Scenario(Scene* scene);
    Scenario();
    bool next();
    SceneCommands currentSceneCommand() const;
    uint32_t currentSceneTime() const;
    
    int currentSceneSpeed();
    float currentSceneKp();
    float currentSceneKi();
    float currentSceneKd();
    int currentSceneDistance();
};