#include "WallMonitor.h"

WallMonitor::WallMonitor(ev3api::SonarSensor& sonarSensor) : mSonarSensor(sonarSensor) {

}

bool WallMonitor::isInRange(int range) {
    return range >= mSonarSensor.getDistance();
}