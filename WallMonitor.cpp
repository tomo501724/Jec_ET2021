#include "WallMonitor.h"

WallMonitor::WallMonitor(ev3api::SonarSensor& sonarSensor) : mSonarSensor(sonarSensor) {

}

bool WallMonitor::isInRange() {
    return mRange >= mSonarSensor.getDistance();
}

void WallMonitor::setRange(int range) {
    this->mRange = range;
}