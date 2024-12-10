#pragma once
class Player {
private:
    int stone; // �΂̐F
public:
    Player(int stoneColor);
    int getStone() const;
    void switchStone();
};