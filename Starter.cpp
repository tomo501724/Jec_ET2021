#include "Starter.h"

Starter::Starter(
    const ev3api::TouchSensor& touchSensor
) : mTouchSensor(touchSensor) {

}

bool Starter::isPushed() const {
    return mTouchSensor.isPressed();
}