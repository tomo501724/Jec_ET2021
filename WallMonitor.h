#pragma once

#include "SonarSensor.h"

// 定義
class WallMonitor {
private:
    ev3api::SonarSensor& mSonarSensor;
    int mRange;

public:
    WallMonitor(ev3api::SonarSensor& sonarSensor);
    bool isInRange();
    void setRange(int range);
};