#include "app.h"
#include "ColorSensor.h"
#include "Motor.h"
#include "LineMonitor.h"
#include "Walker.h"
#include "LineTracer.h"
#include "TouchSensor.h"
#include "Starter.h"
#include "LineTracerWithStarter.h"
#include "ScenarioTracer.h"
#include "Clock.h"
#include "AdvancedSteering.h"
#include "Color.h"

#if defined(BUILD_MODULE)
#include "module_cfg.h"
#else
#include "kernel_cfg.h"
#endif

using ev3api::ColorSensor;
using ev3api::Motor;
//using ev3api::TouchSensor;
using ev3api::Clock;

//ColorSensor gColorSensor(PORT_2);
Motor gLeftWheel(PORT_C);
Motor gRightWheel(PORT_B);
//TouchSensor gTouchSensor(PORT_1);

static LineMonitor *gLineMonitor;
static Walker *gWalker;
static LineTracer *gLineTracer;
//static Starter *gStarter;
//static LineTracerWithStarter *gLineTracerWithStarter;
//static ScenarioTracer *gScenarioTracer;
//static SimpleTimer *gSimpleTimer;
//static Clock *gClock;
static AdvancedSteering *gAdvancedSteering;
static Color *gColor;

static void userSystemCreate()
{
    tslp_tsk(2 * 1000);
    //gClock = new Clock();
    gAdvancedSteering = new AdvancedSteering(gLeftWheel, gRightWheel);
    gWalker = new Walker(gLeftWheel, gRightWheel);
    gColor = new Color(PORT_2);
    gLineMonitor = new LineMonitor(gColor);
    gLineTracer = new LineTracer(gLineMonitor, gWalker);
    //gStarter = new Starter(gTouchSensor);
    //gLineTracerWithStarter = new LineTracerWithStarter(gLineTracer, gStarter);
    //gSimpleTimer = new SimpleTimer(gClock);
    //gScenarioTracer = new ScenarioTracer(gWalker, gSimpleTimer);

    ev3_led_set_color(LED_ORANGE);
}
static void UserSystemDestroy()
{
    gLeftWheel.reset();
    gRightWheel.reset();

    //delete gScenarioTracer;
    //delete gLineTracerWithStarter;
    delete gLineTracer;
    //delete gStarter;
    delete gLineMonitor;
    delete gWalker;
    //delete gClock;
    delete gAdvancedSteering;
    delete gColor;
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
        //gLineTracerWithStarter->run();
    }
    ext_tsk();
}