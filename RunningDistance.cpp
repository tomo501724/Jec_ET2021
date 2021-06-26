/**
 ******************************************************************************
 ** ファイル名 : RunningDistance.cpp
 ** クラス名   : RunningDistance
 **
 ** 概要 : 走行距離の計算を行うクラス
 ******************************************************************************
 **/
#include "RunningDistance.h"

const float RunningDistance::PAI = 3.141592653589793F;

/**
 * デストラクタ
 */
RunningDistance::~RunningDistance() {

}


/**
 * コンストラクタ
 */
RunningDistance::RunningDistance(ev3api::Motor* leftM, ev3api::Motor* rightM)
    : leftMotor(leftM), rightMotor(rightM)
{}

/**
 * 走行距離計算
 * @return 走行距離
 * @comment モーターの回転数から走行距離を計算し値を返す
 */
int RunningDistance::getRunDistance() {
    float leftDistance = 100.8F * PAI * leftMotor->getCount() / 360.0F;
    float rightDistance = 100.8F * PAI * rightMotor->getCount() / 360.0F;
    return (leftDistance + rightDistance) / 2.0F;
}
