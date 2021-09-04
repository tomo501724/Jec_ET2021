#pragma once

#include "ev3api.h"
#include "Scene.h"

class Scenario {
private:
    Scene* mTopScene;
    Scene* mCurrentScene;
    Scene scenes[4] = {
        /*
        {LINE_TRACE, 0, 6630, 100, 0.9f,  0.0f, 103.0f},
        {GO_STRAIGHT, 0, 370, 20, 0.0f,  0.0f, 0.0f},
        {LINE_TRACE, 0, 720, 20, 0.9f,  0.0f, 103.0f},
        {GO_STRAIGHT, 0, 250, 20, 0.0f,  0.0f, 0.0f},
        {LINE_TRACE, 0, 360, 20, 0.9f,  0.0f, 103.0f},
        {GO_STRAIGHT, 0, 10, 20, 0.0f, 0.0f, 0.0f},
        */
        //{LINE_TRACE, 17000, 6630, 100, 0.9f,  0.0f, 103.0f},
        {LINE_TRACE_ON_BLUE, 0, 6800, 100, 0.9f,  0.0f, 103.0f},
        {LINE_TRACE_ON_BLUE, 0, 1250, 20, 0.9f,  0.0f, 103.0f},
        {GO_STRAIGHT, 0, 300, 20, 0.0f, 0.0f, 0.0f},
        //{LINE_TRACE_ON_BLUE, 0, 250, 20, 0.9f,  0.0f, 103.0f},
        //{TURN, 0, 100, 20, 0.9f,  0.0f, 103.0f},
        //{LINE_TRACE_ON_BLUE, 0, 400, 10, 0.9f,  0.0f, 103.0f},
        //{LINE_TRACE_UNTIL_BLUE, 0, 300, 10, 0.9f,  0.0f, 103.0f},
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