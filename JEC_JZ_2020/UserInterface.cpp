/**
 ******************************************************************************
 ** ファイル名 : UserInterface.cpp
 ** クラス名   : UserInterface
 **
 ** 概要 : ユーザー入力を管理するクラス
 ******************************************************************************
 **/
#include "UserInterface.h"

/**
 * コンストラクタ
 */
UserInterface::UserInterface() {
    bt = ev3_serial_open_file(EV3_SERIAL_BT);
}

/**
 * デストラクタ
 */
UserInterface::~UserInterface() {
    fclose(bt);
}


/**
 * 更新
 */
void UserInterface::update() {
    //key = '\0';
    key = fgetc(bt);
}

/**
 * キー押下確認
 * key : 押下確認キー
 * 
 * return : bool
 */
bool UserInterface::isPressedKey(char key) {
    bool b = this->key == key;
    key = '\0';
    return b;
}