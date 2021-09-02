#pragma once

#include "ev3api.h"
#include "Scene.h"

class Scenario {
private:
    Scene* mTopScene;
    Scene* mCurrentScene;
    Scene scenes[7] = {
        {LINE_TRACE_UNTIL_TIME, 140U * 100000U, 67700, 100, 0.9f,  0.0f, 103.0f},
        {LINE_TRACE_UNTIL_TIME, 2U * 1000000U, 67700, 70, 0.9f,  0.0f, 103.0f},
        {LINE_TRACE_UNTIL_TIME, 180U * 10000U, 67700, 100, 0.9f,  0.0f, 103.0f},
        {GO_STRAIGHT, 0, 300, 20, 0.9f,  0.0f, 103.0f},
        {LINE_TRACE_UNTIL_TIME, 76U * 100000U, 790, 20, 0.9f,  0.0f, 103.0f},
        {GO_STRAIGHT, 0, 200, 20, 0.9f,  0.0f, 103.0f},
        /*{LINE_TRACE_UNTIL_TIME, 5U * 1000000U, 3200, 20, 0.9f,  0.0f, 103.0f},
        {GO_STRAIGHT, 0, 100, 20, 0.0f, 0.0f, 0.0f},
        {LINE_TRACE_UNTIL_TIME, 0, 570, 20, 0.9f, 0.0f, 103.0f},
        {GO_STRAIGHT, 0, 40, 20, 0.0f, 0.0f, 0.0f},*/
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