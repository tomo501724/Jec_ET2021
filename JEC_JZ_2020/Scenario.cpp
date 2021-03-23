/**
 ******************************************************************************
 ** ファイル名 : Scenario.cpp
 ** クラス名   : Scenario
 **
 ** 概要 : 走行情報を格納するクラス
 ******************************************************************************
 **/
#include "Scenario.h"

/**
 * コンストラクタ
 * dis    : 走行距離  
 * foward : 走行速度
 */
Scenario::Scenario(int dis, int forward)
        : dis(dis), forward(forward)
{}


/**
 * ゲッタ
 */
int Scenario::getDis() {
    return dis;
}

int Scenario::getForward() {
    return forward;
}