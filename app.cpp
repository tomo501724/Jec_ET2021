#include "app.h"
#include "ColorSensor.h"
#include "Motor.h"
#include "LineMonitor.h"
#include "Walker.h"
#include "LineTracer.h"

#if defined(BUILD_MODULE)
#include "module_cfg.h"
#else
#include "kernel_cfg.h"
#endif

using ev3api::ColorSensor;
using ev3api::Motor;

ColorSensor gColorSensor(PORT_2);
Motor gLeftWheel(PORT_C);
Motor gRightWheel(PORT_B);

static LineMonitor *gLineMonitor;
static Walker *gWalker;
static LineTracer *gLineTracer;

static void userSystemCreate()
{
    gWalker = new Walker(gLeftWheel, gRightWheel);
    gLineMonitor = new LineMonitor(gColorSensor);
    gLineTracer = new LineTracer(gLineMonitor, gWalker);

    ev3_led_set_color(LED_ORANGE);
}
static void UserSystemDestroy()
{
    gLeftWheel.reset();
    gRightWheel.reset();

    delete gLineTracer;
    delete gLineMonitor;
    delete gWalker;
}

void main_task(intptr_t unused)
{
    userSystemCreate();
    
    sta_cyc(CYC_TRACER);
    slp_tsk();

    stp_cyc(CYC_TRACER);
    UserSystemDestroy();
    ext_tsk();
}
void tracer_task(intptr_t exinf)
{
    if (ev3_button_is_pressed(BACK_BUTTON))
    {
        wup_tsk(MAIN_TASK);
    }
    else
    {
        gLineTracer->run();
    }
    ext_tsk();
}