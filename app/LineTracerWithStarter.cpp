#include "LineTracerWithStarter.h"

LineTracerWithStarter::LineTracerWithStarter(
    LineTracer *LineTracer, const Starter *starter)
    : mLineTracer(LineTracer),
      mStarter(starter),
      mState(UNDEFINED) {
}

void LineTracerWithStarter::run(){
    swtich(mState){
        case UNDEFINED:
            execUndefined();
            break;
        case WAITING_FOR_START:
            execWaitingForStart();
            break;
        case WALKING:
            execWalking();
            break;
        default;
            break;
    }
}