/**
 ******************************************************************************
 ** ファイル名 : Screen.h
 ** クラス名   : Screen
 **
 ** 概要 : 液晶画面表示を管理するクラス
 ******************************************************************************
 **/
#pragma once

#include "ev3api.h"

class Screen
{
protected:
    /* data */
public:
    Screen();
    virtual ~Screen();
    virtual void draw() = 0;
    virtual void input(button_t utton) = 0;
};