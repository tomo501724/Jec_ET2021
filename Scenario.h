#pragma once

#include "ev3api.h"
#include "Scene.h"

class Scenario {
private:
    Scene* mTopScene;
    Scene* mCurrentScene;
    Scene scenes[11] = {
        {LINE_TRACE_ON_BLUE, 0, 7250, 100, 0.9f,  0.0f, 103.0f},
        {LINE_TRACE_UNTIL_BLUE, 0, 1250, 20, 0.9f,  0.0f, 99.2f},
        {LINE_TRACE_ON_BLUE, 0, 350, 20, 0.9f,  0.0f, 99.2f},
        {GO_STRAIGHT, 0, 275, 20, 0.0f, 0.0f, 0.0f},
        {LINE_TRACE_ON_BLUE, 0, 450, 20, 0.9f,  0.0f, 99.2f},
        {GO_STRAIGHT, 0, 135, 20, 0.0f, 0.0f, 0.0f},
        {TURN, 0, 125, 20, 0.9f,  0.0f, 103.0f},
        {GO_STRAIGHT, 0, 35, 20, 0.0f, 0.0f, 0.0f},
        {LINE_TRACE_ON_BLUE, 0, 125, 10, 0.9f,  0.0f, 103.0f},
        {WALL_DETECTION, 0, 31000, 20, 0.0f, 0.0f, 0.0f},
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