#include <iostream>
#include "Player.h"
using namespace std;

// �R���X�g���N�^
Player::Player(int stoneColor) : stone(stoneColor) {}

// �΂̎擾
int Player::getStone() const {
    return stone;
}

// �΂�؂�ւ���
void Player::switchStone() {
    stone = (stone == 2) ? 3 : 2;
}