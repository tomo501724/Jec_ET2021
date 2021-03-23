/**
 ******************************************************************************
 ** ファイル名 : Color.h
 ** クラス名   : Color
 **
 ** 概要 : 色を測定するクラス
 ******************************************************************************
 **/
#pragma once

#include "ev3api.h"
#include "ColorSensor.h"

class Color
{
protected:
    ev3api::ColorSensor* colorSensor;
    rgb_raw_t mRgbLevel;       /* RGB構造体 */
    int mRgbTotal;             /* LPF処理後のRGB合計値 */
    int mRgbBefore;            /* LPF処理用メンバー */
    float KLPF = 0.6F;         /* LPF処理用係数 */

public:
    Color(ePortS port);
    ~Color();
    int getRed();
    int getGreen();
    int getBrue();
    int getNaturalTotalRGB();
    int getTotalRGB();
    void update();

};