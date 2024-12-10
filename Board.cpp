#include <iostream>
#include "Board.h"
using namespace std;

Board::Board() {
	makeBoard();
}



// �ŏ��̔Ֆʂ𐶐�����֐� 1 = �Ζ���, 2 = ����, 3 = ����
void Board::makeBoard() {

	// �܂��͉����΂��u����ĂȂ���Ԃ���� (1����)
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++) {
			board[i][j] = 1;
		}
	}

	// �ŏ��̔Ֆʂ����
	board[3][3] = 3;
	board[4][4] = 3;
	board[3][4] = 2;
	board[4][3] = 2;

}

// �΂�u���邩�ǂ������肷��֐� col = ��(���̕���) row = �s(�c�̕���)
bool Board::confirm(int col, int row, int stone) const {

	if (col < 0 || col >= BOARD_SIZE || row < 0 || row >= BOARD_SIZE || board[row][col] != 1) {
		return false;
	}

	int dx[]{ -1, 0, 1, -1, 1, -1, 0, 1 };
	int dy[]{ 1, 1, 1, 0, 0, -1, -1, -1 };

	for (int i = 0; i < 8; i++) {
		int x = dx[i] + row;
		int y = dy[i] + col;

		// �ݒ肵�������ɐi��
		while (x >= 0 && x < BOARD_SIZE && y >= 0 && y < BOARD_SIZE && board[x][y] != 1 && board[x][y] != stone) {
			x += dx[i];
			y += dy[i];
		}
		// ���̕����Ɏ����̐F�̐΂����邩�m�F
		if (x >= 0 && x < BOARD_SIZE && y >= 0 && y < BOARD_SIZE && board[x][y] == stone && (x != row + dx[i] || y != col + dy[i])) {
			return true;
		}
	}
	return false;
}

void Board::showBoard(int stone) const  {

	// �������L���ɒu��������
	cout << "  a b c d e f g h " << endl; // ��̃A���t�@�x�b�g
	for (int i = 0; i < BOARD_SIZE; i++) {
		cout << i + 1 << " ";
		// �u����ꏊ������ꍇ��confirm��true�ɂȂ�̂ł�����*�ŕ\�L����
		// �A�V�X�g�@�\�̂悤�Ȃ��� 
		for (int j = 0; j < BOARD_SIZE; j++) {
			if (confirm(j, i, stone)) {
				cout << "* ";
			}
			else {
				switch (board[i][j]) {
				case 1:
					cout << "�E";
					break;
				case 2:
					cout << "�� ";
					break;
				case 3:
					cout << "�� ";
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

	// �u���Ȃ��ꍇ��false��Ԃ� 
	bool isConfirm = false;

	// ������ݒ� ����A��A�E��A�E�A���A�����A���A�E���̏�
	int dx[]{ -1, 0, 1, -1, 1, -1, 0, 1 };
	int dy[]{ 1, 1, 1, 0, 0, -1, -1, -1 };

	for (int i = 0; i < 8; i++) {
		int x = dx[i] + row;
		int y = dy[i] + col;

		// �ݒ肵�������ɐi��
		while (x >= 0 && x < BOARD_SIZE && y >= 0 && y < BOARD_SIZE && board[x][y] != 1 && board[x][y] != stone) {
			x += dx[i];
			y += dy[i];
		}
		// ���̕����Ɏ����̐F�̐΂����邩�m�F���A�߂�F��ς���
		if (x >= 0 && x < BOARD_SIZE && y >= 0 && y < BOARD_SIZE && board[x][y] == stone && (x != row + dx[i] || y != col + dy[i])) {
			isConfirm = true; // ������true�ɂ���
			while (x != row || y != col) {
				x -= dx[i];
				y -= dy[i];
				board[x][y] = stone;
			}
		}
	}

	// confirn��false��������false��Ԃ�
	if (!isConfirm) {
		return false;
	}

	// �΂�u��
	board[row][col] = stone;
	return true;
}

// �u���邩�m�F����֐�
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

// �΂̐����J�E���g
int Board::countStones(int stone) const {
	int count = 0;
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++) {
			if (board[i][j] == stone) count++;
		}
	}
	return count;
}