/**
 ******************************************************************************
 ** ファイル名 : LinetraceScenario.cpp
 ** クラス名   : LinetraceScenario
 **
 ** 概要 : ライントレース走行情報を格納するクラス
 ** 継承元
 ** ファイル名 : Scenario.h
 ** クラス名   : Scenario
 ******************************************************************************
 **/
#include "LinetraceScenario.h"

/**
 * コンストラクタ
 * dis      : 走行距離
 * forward  : 速度（-100 ~ 100）
 * kp       : P値
 * ki       : I値
 * kd       : D値
 */
LinetraceScenario::LinetraceScenario(int dis, int forward, float kp, float ki, float kd, float krgb) 
    : Scenario(dis, forward), kp(kp), ki(ki), kd(kd), krgb(krgb)
{}

/**
 * ゲッタ
 */
float LinetraceScenario::getKp() {
    return kp;
}

float LinetraceScenario::getKi() {
    return ki;
}

float LinetraceScenario::getKd() {
    return kd;
}

float LinetraceScenario::getKrgb() {
    return krgb;
}