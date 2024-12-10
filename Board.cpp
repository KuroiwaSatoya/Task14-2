#include <iostream>
#include "Board.h"
using namespace std;

Board::Board() {
	makeBoard();
}



// 最初の盤面を生成する関数 1 = 石無し, 2 = 黒○, 3 = 白●
void Board::makeBoard() {

	// まずは何も石が置かれてない状態を作る (1を代入)
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++) {
			board[i][j] = 1;
		}
	}

	// 最初の盤面を作る
	board[3][3] = 3;
	board[4][4] = 3;
	board[3][4] = 2;
	board[4][3] = 2;

}

// 石を置けるかどうか判定する関数 col = 列(横の並び) row = 行(縦の並び)
bool Board::confirm(int col, int row, int stone) const {

	if (col < 0 || col >= BOARD_SIZE || row < 0 || row >= BOARD_SIZE || board[row][col] != 1) {
		return false;
	}

	int dx[]{ -1, 0, 1, -1, 1, -1, 0, 1 };
	int dy[]{ 1, 1, 1, 0, 0, -1, -1, -1 };

	for (int i = 0; i < 8; i++) {
		int x = dx[i] + row;
		int y = dy[i] + col;

		// 設定した方向に進む
		while (x >= 0 && x < BOARD_SIZE && y >= 0 && y < BOARD_SIZE && board[x][y] != 1 && board[x][y] != stone) {
			x += dx[i];
			y += dy[i];
		}
		// その方向に自分の色の石があるか確認
		if (x >= 0 && x < BOARD_SIZE && y >= 0 && y < BOARD_SIZE && board[x][y] == stone && (x != row + dx[i] || y != col + dy[i])) {
			return true;
		}
	}
	return false;
}

void Board::showBoard(int stone) const  {

	// 数字を記号に置き換える
	cout << "  a b c d e f g h " << endl; // 上のアルファベット
	for (int i = 0; i < BOARD_SIZE; i++) {
		cout << i + 1 << " ";
		// 置ける場所がある場合はconfirmがtrueになるのでそこを*で表記する
		// アシスト機能のようなもの 
		for (int j = 0; j < BOARD_SIZE; j++) {
			if (confirm(j, i, stone)) {
				cout << "* ";
			}
			else {
				switch (board[i][j]) {
				case 1:
					cout << "・";
					break;
				case 2:
					cout << "○ ";
					break;
				case 3:
					cout << "● ";
					break;
				}
			}
		}
		cout << endl;
	}
	cout << endl;

}
bool Board::putAStone(int col, int row, int stone) {

	if (col < 0 || col > BOARD_SIZE || row < 0 || row > BOARD_SIZE || board[row][col] != 1) {
		return false;
	}

	// 置けない場合にfalseを返す 
	bool isConfirm = false;

	// 方向を設定 左上、上、右上、右、左、左下、下、右下の順
	int dx[]{ -1, 0, 1, -1, 1, -1, 0, 1 };
	int dy[]{ 1, 1, 1, 0, 0, -1, -1, -1 };

	for (int i = 0; i < 8; i++) {
		int x = dx[i] + row;
		int y = dy[i] + col;

		// 設定した方向に進む
		while (x >= 0 && x < BOARD_SIZE && y >= 0 && y < BOARD_SIZE && board[x][y] != 1 && board[x][y] != stone) {
			x += dx[i];
			y += dy[i];
		}
		// その方向に自分の色の石があるか確認し、戻りつつ色を変える
		if (x >= 0 && x < BOARD_SIZE && y >= 0 && y < BOARD_SIZE && board[x][y] == stone && (x != row + dx[i] || y != col + dy[i])) {
			isConfirm = true; // ここでtrueにする
			while (x != row || y != col) {
				x -= dx[i];
				y -= dy[i];
				board[x][y] = stone;
			}
		}
	}

	// confirnがfalseだったらfalseを返す
	if (!isConfirm) {
		return false;
	}

	// 石を置く
	board[row][col] = stone;
	return true;
}

// 置けるか確認する関数
bool Board::canPut(int stone) {
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0;j < BOARD_SIZE; j++) {
			if (confirm(i, j, stone)) {
				return true;
			}
		}
	}
	return false;
}

// 石の数をカウント
int Board::countStones(int stone) const {
	int count = 0;
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++) {
			if (board[i][j] == stone) count++;
		}
	}
	return count;
}