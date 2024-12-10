#include <iostream>
#include "Board.h"
#include "Player.h"
using namespace std;

int main() {

	Board board;

	Player blackPlayer(2), whitePlayer(3);

	Player* nowPlayer = &blackPlayer;

	// ����1�x�v���C���邽�߂̂���
	char playAgain = 'y';

	board.makeBoard();
	while (true) {
		if (playAgain == 'y') {
			while (true) {

				// �Ֆʂ�\��
				board.showBoard(nowPlayer->getStone());	

				// �u����ꏊ�������ꍇ�X�L�b�v����
				if (!board.canPut(nowPlayer->getStone())) {
					nowPlayer->switchStone();

					// �v���C���[����サ�Ă��u����ꏊ���Ȃ��ꍇ�̓Q�[�����I������
					if (!board.canPut(nowPlayer->getStone())) {
						cout << "�o���u����ꏊ������܂���B�Q�[�����I�����܂��B" << endl;
						break;
					}

					// switchPlayer�֐������łɌĂяo���Ă���̂ō��Ɣ����t�ɂ���
					cout << (nowPlayer->getStone() == 2 ? "����" : "����") << "�͒u����Ƃ��낪����܂���B�^�[�����X�L�b�v���܂��B" << endl;
					continue;
				}

				// col = ��(���̕���) row = �s(�c�̕���)
				int col = -1, row = -1;

				// ������col (���͂̍ہA��̔���̓A���t�@�x�b�g�̂���)
				char col_char;

				bool isInputAgain = true;

				while (isInputAgain) {
					// �\��
					cout << (nowPlayer->getStone() == 2 ? "����" : "����") << "�̔Ԃł��B�u�������ꏊ����͂��Ă��������B(��: f5) (��߂�ꍇ��n0�����)> " << flush;

					// ����
					cin >> col_char >> row;

					// a��0�Ab��1...��col�ɑ��
					if (col_char == 'a' && row >= 1 && row <= 8) {
						col = 0; isInputAgain = false;
					}
					else if (col_char == 'b' && row >= 1 && row <= 8) {
						col = 1; isInputAgain = false;
					}
					else if (col_char == 'c' && row >= 1 && row <= 8) {
						col = 2; isInputAgain = false;
					}
					else if (col_char == 'd' && row >= 1 && row <= 8) {
						col = 3; isInputAgain = false;
					}
					else if (col_char == 'e' && row >= 1 && row <= 8) {
						col = 4; isInputAgain = false;
					}
					else if (col_char == 'f' && row >= 1 && row <= 8) {
						col = 5; isInputAgain = false;
					}
					else if (col_char == 'g' && row >= 1 && row <= 8) {
						col = 6; isInputAgain = false;
					}
					else if (col_char == 'h' && row >= 1 && row <= 8) {
						col = 7; isInputAgain = false;
					}
					else if (col_char == 'n' && row == 0) {
						cout << "n0�����͂���܂����B���o�[�V���I�����܂��B" << endl;
						return 0;
					}
					else {
						cout << "�����Ə����ĂˁB" << endl;
						continue;
					}
				}

				//row�̒l��1����(�\������Ă���1�A2...��board�ł�0�A1...�ɂȂ邽��) 
				row--;

				// �m�F�A�΂�u����Ȃ�{�[�h�\�����Ԍ��
				if (board.confirm(col, row, nowPlayer->getStone()) && board.putAStone(col, row, nowPlayer->getStone())) {
					nowPlayer->switchStone();
				}
				//�u���Ȃ��̂Ȃ炻���ɂ͒u���܂����Ԃ�
				else {
					cout << "�����ɂ͒u���܂���B" << endl;
				}
			}

			// �ǂ���̏��������肷��

			board.showBoard(nowPlayer->getStone());

			int blackCount = board.countStones(2);
			int whiteCount = board.countStones(3);

			cout << blackCount << "(���Z)��" << whiteCount << "(����)��" << endl;
			if (blackCount > whiteCount) {
				cout << "���̏����I" << endl;
			}
			else if (blackCount < whiteCount) {
				cout << "���̏����I" << endl;
			}
			else {
				cout << "��������" << endl;
			}
		}
		else if (playAgain == 'n') {
			cout << "���o�[�V���I�����܂�" << endl;
			break;
		}
		else {
			cout << "������x���͂��Ă��������B" << endl;
		}

		Player* nowPlayer = &blackPlayer;
		board.makeBoard();

		cout << "����1�x�v���C���܂����H (����ꍇ: y����� ���Ȃ��ꍇ: n�����) > " << flush;
		cin >> playAgain;

		if (playAgain == 'n') {
			break;
		}
	}
}
