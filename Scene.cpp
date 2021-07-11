#include "Scene.h"

Scene::Scene(SceneCommands command, int time, int distance, float kp, float ki, float kd)
: command(command), time(time), distance(distance), kp(kp), ki(ki), kd(kd)
{
}