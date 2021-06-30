#pragma once

#include "SonarSensor.h"

// 定義
class WallMonitor {
public:
    WallMonitor(SonarSensor& sonarSensor);
    bool isInRange();
    void setRange(int range);

private:
    SonarSensor& mSonarSensor;
    int mRange;
}