#pragma once

#include "ev3api.h"
#include "Motor.h"

/**
 * thisポインタについて
 * 自クラスの変数・関数名で衝突が無いことが確実であればthisは省略してもいいです
 * 明確な区別が可能ですが短い関数だとかえって見づらくなる恐れがあります
 * 6~7行を超えるような規模の関数を作るときは後々宣言されるであろう名前とバッティングを避けるために
 * thisで書いておくとよいでしょう
 * 
 * 演算子のインデントについて
 * + や < = などの演算子はスペースをいれて見やすくしましょう
 * 
 * speed < 0 
 * 
 * ただしアロー演算子とドット演算子はスペースを入れないでください
 * 
 * this->speed = speed
 * 
 * その他は完璧です
 * 
 */

class Runner{
    private:
        ev3api::Motor* leftMotor;
        ev3api::Motor* rightMotor;
        int speed;
    public:
        Runner(
            ev3api::Motor* leftMotor
            ,ev3api::Motor* rightMotor
            ,int speed);
        
        void forward();
        void back();
        void turnLeft();
        void turnRight();
        void stop();

        void setSpeed(int speed);
        int getSpeed();
};
