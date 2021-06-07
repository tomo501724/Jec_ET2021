#pragma once

#include "../LineTracer.h"
#include "Starter.h"

class LineTracerWithStarter
{
public:
    LineTracerWithStarter(
        LineTracer *LineTracer,
        const Starter *starter);
    void run();

private:
    LineTracer *mLineTracer;
    const Starter *mStarter;
}