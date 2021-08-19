#pragma once

#include "ev3api.h"
#include "Scene.h"

class Scenario {
private:
    Scene* mTopScene;
    Scene* mCurrentScene;
    Scene scenes[6] = {
        {LINE_TRACE, 0, 6600, 100, 0.9f,  0.0f, 103.0f},
        {GO_STRAIGHT, 0, 350, 1, 0.0f,  0.0f, 0.0f},
        {LINE_TRACE, 0, 720, 1, 0.9f,  0.0f, 103.0f},
        {GO_STRAIGHT, 0, 200, 1, 0.0f,  0.0f, 0.0f},
        {LINE_TRACE, 0, 360, 1, 0.9f,  0.0f, 103.0f},
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