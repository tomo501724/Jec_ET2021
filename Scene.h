#pragma once
#include "SceneCommands.h"

class Scene
{
public:
    SceneCommands command;
    int time;
    Scene* next;
    Scene(SceneCommands command, int time);
};