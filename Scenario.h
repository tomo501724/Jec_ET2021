#pragma once

#include "ev3api.h"
#include "Scene.h"

class Scenario {
private:
    Scene* mTopScene;
    Scene* mCurrentScene;
    Scene scenes[7] = {
        {LINE_TRACE, 0, 6650, 100, 0.9f,  0.0f, 103.0f},
        {GO_STRAIGHT, 0, 350, 20, 0.0f,  0.0f, 0.0f},
        {LINE_TRACE, 0, 720, 20, 0.9f,  0.0f, 103.0f},
        {GO_STRAIGHT, 0, 200, 20, 0.0f,  0.0f, 0.0f},
        {LINE_TRACE, 0, 360, 20, 0.9f,  0.0f, 103.0f},
        {GO_STRAIGHT, 0, 10, 20, 0.0f, 0.0f, 0.0f},
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