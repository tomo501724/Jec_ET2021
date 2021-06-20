/**
 ******************************************************************************
 ** ファイル名 : Color.cpp
 ** クラス名   : Color
 **
 ** 概要 : 色を測定するクラス
 ******************************************************************************
 **/
#include "Color.h"

const float Color::KLPF = 0.6F;

/**
 * コンストラクタ
 */
Color::Color(ePortS port) {
    colorSensor = new ev3api::ColorSensor(port);
}

/**
 * デストラクタ
 */
Color::~Color(){
	delete colorSensor;
}

/* ゲッター */
int Color::getRed() {
    return mRgbLevel.r;
}
int Color::getGreen() {
    return mRgbLevel.g;
}
int Color::getBrue() {
    return mRgbLevel.b;
}
int Color::getNaturalTotalRGB() {
    return (mRgbLevel.r + mRgbLevel.g + mRgbLevel.b);
}
int Color::getTotalRGB() {
    return mRgbTotal;
}

/**
 * 色判定
 * rgb_raw_t& rgbRaw : 比較するRGB値
 * uint16_t diff : 目標値からの許容誤差
 */
bool Color::isColor(rgb_raw_t& rgbRaw, uint16_t diff) {
    return rgbRaw.r - diff <= mRgbLevel.r && rgbRaw.r + diff <= mRgbLevel.r &&
           rgbRaw.g - diff <= mRgbLevel.g && rgbRaw.g + diff <= mRgbLevel.g &&
           rgbRaw.b - diff <= mRgbLevel.b && rgbRaw.b + diff <= mRgbLevel.b;
}

/**
 * rgb_raw_t 取得
 */
rgb_raw_t Color::getNaturalRGB() {
    return this->mRgbLevel;
}

/**
 * 更新
 * LPF計算もここで行っている
 */
void Color::update() {
    mRgbBefore = mRgbTotal;
    colorSensor->getRawColor(mRgbLevel);
    mRgbTotal = getNaturalTotalRGB() * KLPF + mRgbBefore * (1 - KLPF);
}
