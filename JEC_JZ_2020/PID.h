/**
 ******************************************************************************
 ** ファイル名 : PID.h
 ** クラス名   : PID
 **
 ** 概要 : PID制御の計算を行うクラス
 ******************************************************************************
 **/
#pragma once

class PID
{
private:
    float kp = 0.0f;            /* 比例定数 */
    float ki = 0.0f;            /* 積分定数 */
    float kd = 0.0f;            /* 微分定数 */
    int diff[2] = {0, 0};       /* カラー格納用変数 */
    float integral = 0.0f;      /* 積分計算用変数 */
    const float LIMIT = 100.0;  /* 最大最小の制限 */

public:
    void setPID(float pValue, float iValue, float dValue);
    int calcControl(int nowValue);

};