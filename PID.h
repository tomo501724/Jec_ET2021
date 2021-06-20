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
    float kp;            /* 比例定数 */
    float ki;            /* 積分定数 */
    float kd;            /* 微分定数 */
    int diff[2];       /* カラー格納用変数 */
    float integral;      /* 積分計算用変数 */
    static const float LIMIT;  /* 最大最小の制限 */

public:
    PID();
    PID(float kp, float ki, float kd);
    void setPID(float pValue, float iValue, float dValue);
    int calcControl(int nowValue);

};