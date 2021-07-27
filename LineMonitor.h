/******************************************************************************
 *  LineMonitor.h (for LEGO Mindstorms EV3)
 *  Created on: 2015/01/25
 *  Definition of the Class LineMonitor
 *  Author: Kazuhiro Kawachi
 *  Copyright (c) 2015 Embedded Technology Software Design Robot Contest
 *****************************************************************************/

#pragma once

#include "Color.h"

// 定義
class LineMonitor {
private:
    Color& mColor;
    static const int8_t INITIAL_THRESHOLD = 20;
    int8_t mThreshold = INITIAL_THRESHOLD;
    rgb_raw_t BLUE_RGB = {20U, 46U, 93U};

public:
    LineMonitor(Color& color);
    int getRGB();
    bool isOnBlue();

};
