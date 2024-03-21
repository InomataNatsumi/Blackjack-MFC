
#pragma once

#include <string>

class Card {

public:

	//マークの関数
	static std::string cM(int ca);

	//カードの数の関数
	static char* cN(int ca2);

};


class Score {

public:

	//あなたのカードがAの関数
	static bool A(int ca);

	//あなたの得点の関数
	static int YcP(int ca3);

	//ディーラーの得点の関数
	static int DcP(int ca4, int DS);

};