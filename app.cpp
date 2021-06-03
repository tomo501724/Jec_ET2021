#include "app.h"
#include "LineTracer.h"

#if defined(BUILD_MODULE)
#include "module_cfg.h"
#else
#include "kernel_cfg.h"
#endif

using ev3api::ColorSensor;
using ev3api::Motor;

ColorSensor gColorSensor(PORT_2);
Motor       gLeftWheel(PORT_C);
Motor       gRightWheel(PORT_B);

static LineMotor*  gLineMonitor;
static Walker*     gWalker;
static LineTracer* gLineTracer;

static void userSystemCreate(){
    gWalker = new Walker(gLeftWheel, gRightWheel);
    gLineMonitor = new LineMonitor(gColorSensor);
    gLineTracer = new LineTracer(gLineMonitor,gWalker);

    ev3_led_set_color(LED_ORANGE);
}
static void UserSystemDestroy(){
    gLeftWheel.reset();
    gRightWheel.reset();

    delete gLineTracer;
    delete gLineMonitor;
    delete gWalker;
}