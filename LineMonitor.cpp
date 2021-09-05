/******************************************************************************
 *  LineMonitor.cpp (for LEGO Mindstorms EV3)
 *  Created on: 2015/01/25
 *  Definition of the Class LineMonitor
 *  Author: Kazuhiro Kawachi
 *  Copyright (c) 2015 Embedded Technology Software Design Robot Contest
 *****************************************************************************/

#include "LineMonitor.h"


LineMonitor::LineMonitor(Color& color) : mColor(color) {

}

int LineMonitor::getRGB() {
    mColor.update();
    return mColor.getTotalRGB();
}

bool LineMonitor::isOnBlue() {
    return mColor.isColor(BLUE_RGB, 5);
}