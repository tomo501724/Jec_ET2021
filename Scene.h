#pragma once
#include "SceneCommands.h"

class Scene
{
public:
    SceneCommands command;
    int time;
    int distance;
    int speed;
    float kp;
    float ki;
    float kd;

    Scene* next;

    Scene(SceneCommands command, int time, int distance, int speed, float kp, float ki, float kd);
};