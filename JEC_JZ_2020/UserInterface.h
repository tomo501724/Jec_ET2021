/**
 ******************************************************************************
 ** ファイル名 : UserInterface.h
 ** クラス名   : UserInterface
 **
 ** 概要 : ユーザー入力を管理するクラス
 ******************************************************************************
 **/
#pragma once

#include "ev3api.h"

class UserInterface
{
private:
    char key;
    FILE* bt;
public:
    UserInterface();
    ~UserInterface();
    void update();
    bool isPressedKey(char key);
};