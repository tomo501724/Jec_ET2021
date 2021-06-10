#pragma once

#include "ev3api.h"
#include "Scene.h"

class Scenario {
public:
    explicit Scenario(Scene* scene);

    void add(Scene* scene);
    Scene* top() const;
    Scene* current() const;
    Scene* next();
    SceneCommands currentSceneCommand() const;
    uint32_t currentSceneTime() const;

private:
    Scene* mTopScene;
    Scene* mCurrentScene;
};