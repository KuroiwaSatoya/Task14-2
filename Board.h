#pragma once
#include <iostream>
using namespace std;

const int BOARD_SIZE = 8;

class Board {

private :
	int board[BOARD_SIZE][BOARD_SIZE];

public:
	Board();
	void makeBoard();
	void showBoard(int stone) const ;
	bool confirm(int col, int row, int stone) const ;
	bool putAStone(int col, int row, int stone);
	bool canPut(int stone);
	int countStones(int stone) const ;
};
