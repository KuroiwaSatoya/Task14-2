#include <iostream>
#include "Board.h"
#include "Player.h"
using namespace std;

int main() {

	Board board;

	Player blackPlayer(2), whitePlayer(3);

	Player* nowPlayer = &blackPlayer;

	// もう1度プレイするためのもの
	char playAgain = 'y';

	board.makeBoard();
	while (true) {
		if (playAgain == 'y') {
			while (true) {

				// 盤面を表示
				board.showBoard(nowPlayer->getStone());	

				// 置ける場所が無い場合スキップする
				if (!board.canPut(nowPlayer->getStone())) {
					nowPlayer->switchStone();

					// プレイヤーを交代しても置ける場所がない場合はゲームを終了する
					if (!board.canPut(nowPlayer->getStone())) {
						cout << "双方置ける場所がありません。ゲームを終了します。" << endl;
						break;
					}

					// switchPlayer関数をすでに呼び出しているので黒と白を逆にする
					cout << (nowPlayer->getStone() == 2 ? "白●" : "黒○") << "は置けるところがありません。ターンをスキップします。" << endl;
					continue;
				}

				// col = 列(横の並び) row = 行(縦の並び)
				int col = -1, row = -1;

				// 文字版col (入力の際、列の判定はアルファベットのため)
				char col_char;

				bool isInputAgain = true;

				while (isInputAgain) {
					// 表示
					cout << (nowPlayer->getStone() == 2 ? "黒○" : "白●") << "の番です。置きたい場所を入力してください。(例: f5) (やめる場合はn0を入力)> " << flush;

					// 入力
					cin >> col_char >> row;

					// aを0、bを1...とcolに代入
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
						cout << "n0が入力されました。リバーシを終了します。" << endl;
						return 0;
					}
					else {
						cout << "ちゃんと書いてね。" << endl;
						continue;
					}
				}

				//rowの値を1引く(表示されている1、2...はboardでは0、1...になるため) 
				row--;

				// 確認、石を置けるならボード表示し番交代
				if (board.confirm(col, row, nowPlayer->getStone()) && board.putAStone(col, row, nowPlayer->getStone())) {
					nowPlayer->switchStone();
				}
				//置けないのならそこには置けませんを返す
				else {
					cout << "そこには置けません。" << endl;
				}
			}

			// どちらの勝ちか判定する

			board.showBoard(nowPlayer->getStone());

			int blackCount = board.countStones(2);
			int whiteCount = board.countStones(3);

			cout << blackCount << "(黒〇)対" << whiteCount << "(白●)で" << endl;
			if (blackCount > whiteCount) {
				cout << "黒の勝ち！" << endl;
			}
			else if (blackCount < whiteCount) {
				cout << "白の勝ち！" << endl;
			}
			else {
				cout << "引き分け" << endl;
			}
		}
		else if (playAgain == 'n') {
			cout << "リバーシを終了します" << endl;
			break;
		}
		else {
			cout << "もう一度入力してください。" << endl;
		}

		Player* nowPlayer = &blackPlayer;
		board.makeBoard();

		cout << "もう1度プレイしますか？ (する場合: yを入力 しない場合: nを入力) > " << flush;
		cin >> playAgain;

		if (playAgain == 'n') {
			break;
		}
	}
}
