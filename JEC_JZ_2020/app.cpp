

#include "ev3api.h"
#include "app.h"
#include "etroboc_ext.h"

#include "LinetraceRun.h"
#include "NoLinetraceRun.h"
#include <stdlib.h>

#define DEBUG

#ifdef DEBUG
#define _debug(x) (x)
#else
#define _debug(x)
#endif

/**
 * 左右コース指定
 */
#if defined(MAKE_RIGHT)
    static const int _COURSE = 0;
#else
    static const int _COURSE = 1;
#endif

LinetraceRun* linetrace;
NoLinetraceRun* noLinetrace;

/**
 * 初期化タスク
 * unused 拡張情報
 */
void initTask(intptr_t unused)
{
    syslog(LOG_NOTICE, "Initalizing...");
    linetrace       = new LinetraceRun(_COURSE);
    noLinetrace     = new NoLinetraceRun(_COURSE, 1);

    //act_tsk(BT_TASK);
    act_tsk(START_WAIT_TASK);
    ext_tsk();
}


/**
 * スタート待機タスク
 */
void startWaitTask(intptr_t exinf)
{ 
    syslog(LOG_NOTICE, "START WAITING");
    while (true)
    {
        linetrace->startWait();
        tslp_tsk(4 * 1000U);
    }   
       
}


/**
 * ライントレース走行タスク
 */
void linetraceTask(intptr_t exinf)
{
    while (true)
    {
        linetrace->running();
        tslp_tsk(4 * 1000U);
    }
    
}

/**
 * ライントレースなし走行タスク
 */
void noLinetraceTask(intptr_t exinf)
{
    syslog(LOG_NOTICE, "NOLINETRACE");
    while (true)
    {
        noLinetrace->running();
        tslp_tsk(4 * 1000U);
    }
    
}

/**
 * ライントレースなし走行初期化タスク
 */
void noLinetraceInitTask(intptr_t exinf)
{
    noLinetrace->startWait();
}


/**
 * 終了タスク
 */
void exitTask(intptr_t exinf)
{
    ter_tsk(BT_TASK);
    delete linetrace;
    delete noLinetrace;
    syslog(LOG_NOTICE, "EXIT");
    ETRoboc_notifyCompletedToSimulator();
    exit(0);
}

/**
 * Bluetoothタスク
 */
void btTask(intptr_t exinf)
{
    while (true)
    {
        linetrace->btUpdate();
    }
}