#include "Scene.h"

Scene::Scene(SceneCommands command, int time, int speed, int distance, float kp, float ki, float kd)
: command(command), time(time), distance(distance), speed(speed), kp(kp), ki(ki), kd(kd)
{
}