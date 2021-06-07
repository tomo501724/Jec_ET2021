#include "LineTracerWithStarter.h"

LineTracerWithStarter::LineTracerWithStarter(
    LineTracer *LineTracer, const Starter *starter)
    : mLineTracer(LineTracer),
      mStarter(starter),
      mState(UNDEFINED) {
}

void LineTracerWithStarter::run(){

}