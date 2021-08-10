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
#include "Scenario.h"
#include "SceneCommands.h"
#include "Scene.h"
#include "etroboc_ext.h"
#include "WallMonitor.h"
#include "SonarSensor.h"

#if defined(BUILD_MODULE)
#include "module_cfg.h"
#else
#include "kernel_cfg.h"
#endif

using ev3api::ColorSensor;
using ev3api::Motor;
using ev3api::TouchSensor;
using ev3api::Clock;
using ev3api::SonarSensor;

Motor gLeftWheel(PORT_C);
Motor gRightWheel(PORT_B);
TouchSensor gTouchSensor(PORT_1);
SonarSensor gSonarSensor(PORT_3);

static LineMonitor *gLineMonitor;
static Walker *gWalker;
static LineTracer *gLineTracer;
//static Starter *gStarter;
//static LineTracerWithStarter *gLineTracerWithStarter;
static ScenarioTracer *gScenarioTracer;
static SimpleTimer *gSimpleTimer;
static Clock *gClock;
static AdvancedSteering *gAdvancedSteering;
static Color *gColor;
static Scenario *gScnario;
static WallMonitor *gWallMonitor;

static void userSystemCreate()
{
    tslp_tsk(2 * 1000);
    gClock = new Clock();
    gAdvancedSteering = new AdvancedSteering(gLeftWheel, gRightWheel);
    gWalker = new Walker(gLeftWheel, gRightWheel, *gAdvancedSteering);
    gColor = new Color(PORT_2);
    gLineMonitor = new LineMonitor(*gColor);
    gScnario = new Scenario();
    gLineTracer = new LineTracer(gLineMonitor, gWalker, gScnario);
    gSimpleTimer = new SimpleTimer(gClock);
    gWallMonitor = new WallMonitor(gSonarSensor);
    gScenarioTracer = new ScenarioTracer(gWalker, gSimpleTimer, gWallMonitor, gScnario);

    ev3_led_set_color(LED_ORANGE);
}
static void UserSystemDestroy()
{
    gLeftWheel.reset();
    gRightWheel.reset();

    delete gScenarioTracer;
    delete gLineTracer;
    delete gLineMonitor;
    delete gWalker;
    delete gClock;
    delete gAdvancedSteering;
    delete gColor;
    delete gScnario;
    delete gWallMonitor;
}

static void start_wait()
{
    while (!gTouchSensor.isPressed())
    {}
}

void main_task(intptr_t unused)
{
    userSystemCreate();
    
    start_wait();
    sta_cyc(CYC_TRACER);
    slp_tsk();

    stp_cyc(CYC_TRACER);
    UserSystemDestroy();
    ETRoboc_notifyCompletedToSimulator();
    ext_tsk();
}
void tracer_task(intptr_t exinf)
{
    if (ev3_button_is_pressed(BACK_BUTTON) || gScnario->currentSceneCommand() == END)
    {
        wup_tsk(MAIN_TASK);
        syslog(LOG_NOTICE ,"END");
    }
    else
    {
        if (gScnario->currentSceneCommand() == LINE_TRACE)
        {
            gLineTracer->run();
        }
        else
        {
            gScenarioTracer->run();
        }
    }
    ext_tsk();
}