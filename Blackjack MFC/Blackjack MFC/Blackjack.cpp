
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "pch.h"
#include "Blackjack.h"
#include <iostream>
#include "Blackjack MFCDlg.h"


//マークの関数
std::string Card::cM(int ca) {

	if ((ca - 1) / 13 == 0) {
		return "S";
	}
	else if ((ca - 1) / 13 == 1) {
		return "C";
	}
	else if ((ca - 1) / 13 == 2) {
		return "H";
	}
	else if ((ca - 1) / 13 == 3) {
		return "D";
	}
	else {
		return "エラー";
	}

}

//カードの数の関数
char* Card::cN(int ca2) {

	static char ca[3];

	if (ca2 % 13 == 0) {
		strcpy_s(ca, sizeof(ca), "K");
	}

	else if (ca2 % 13 == 12) {
		strcpy_s(ca, sizeof(ca), "Q");
	}

	else if (ca2 % 13 == 11) {
		strcpy_s(ca, sizeof(ca), "J");
	}

	else if (ca2 % 13 == 1) {
		strcpy_s(ca, sizeof(ca), "A");
	}

	else {
		_itoa_s(ca2 % 13, ca, sizeof(ca), 10);
	}

	return ca;
}


//あなたのカードがAの関数
bool Score::A(int ca) {

	if (ca % 13 == 1) {
		return true;
	}
	else {
		return false;
	}
}



//あなたの得点の関数
int Score::YcP(int ca3) {

	//カードが11・12か13
	if (ca3 % 13 > 10 || ca3 % 13 == 0) {
		return 10;
	}

	//カードが2・3・4・5・6・7・8・9・10
	else {
		return ca3 % 13;
	}

	return 0;
}



//ディーラーの得点の関数
int Score::DcP(int ca4, int DS) {

	int num3 = 0;

	//カードが11・12か、13
	if (ca4 % 13 > 10 || ca4 % 13 == 0) {
		return 10;
	}
	//カードがエース
	else if (ca4 % 13 == 1) {

		//ディーラーが11を選んだ時17を超えなければランダムで1か11
		if (DS + 11 <= 17) {
			srand((unsigned int)time(NULL));
			num3 = rand() % 2;

			if (num3 == 1) {
				return 1;
			}
			else if (num3 == 0) {
				return 11;
			}
		}

		//ディーラーが11を選んだら17を超えるなら1を選ぶ
		else if (DS + 11 > 17) {
			return 1;
		}
	}

	//カードが2・3・4・5・6・7・8・9・10
	else {
		return ca4 % 13;
	}

	return 0;
}