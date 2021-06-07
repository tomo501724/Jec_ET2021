#pragma once
#include "TouchSensor.h"

class Starter {
public:
    explicit Starter(
        const ev3api::TouchSensor& touchSensor
    );

    bool isPushed() const;

private:
    const ev3api::TouchSensor& mTouchSensor;
};