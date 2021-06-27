#pragma once
#include "SceneCommands.h"

class Scene
{
public:
    int speed, distance;
    
    float kp;
    float ki;
    float kd;

    SceneCommands command;
    int time;
    Scene* next;
    Scene(SceneCommands command, int time);
};