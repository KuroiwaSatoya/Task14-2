#include <iostream>
#include "Player.h"
using namespace std;

// コンストラクタ
Player::Player(int stoneColor) : stone(stoneColor) {}

// 石の取得
int Player::getStone() const {
    return stone;
}

// 石を切り替える
void Player::switchStone() {
    stone = (stone == 2) ? 3 : 2;
}