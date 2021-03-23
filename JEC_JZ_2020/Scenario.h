/**
 ******************************************************************************
 ** ファイル名 : Scenario.h
 ** クラス名   : Scenario
 **
 ** 概要 : 走行情報を格納するクラス
 ******************************************************************************
 **/
#pragma once

class Scenario 
{

protected:
    int dis;        /* 設定距離 */
    int forward;    /* 前進速度 */

public:
    /**
     * コンストラクタ
     * @param dis
     * @param forward
     */
    Scenario(int dis, int forward);
    int getDis();
    int getForward();
};
