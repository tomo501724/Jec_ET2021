#include "LineTracerWithStarter.h"

LineTracerWithStarter::LineTracerWithStarter(
    LineTracer *LineTracer, const Starter *starter)
    : mLineTracer(LineTracer),
      mStarter(starter),
      mState(UNDEFINED)
{
}

void LineTracerWithStarter::run()
{
    switch(mState)
    {
    case UNDEFINED:
        execUndefined();
        break;
    case WAITING_FOR_START:
        execWaitingForStart();
        break;
    case WALKING:
        execWalking();
        break;
        default:
        break;
    }
}

// UNDEFINEDの処理
void LineTracerWithStarter::execUndefined()
{
    mState = WAITING_FOR_START;
}

// WAITING_FOR_STARTの処理
void LineTracerWithStarter::execWaitingForStart()
{
    if (mStarter->isPushed())
    {
        mState = WALKING;
    }
}

void LineTracerWithStarter::execWalking()
{
    mLineTracer->run();
}