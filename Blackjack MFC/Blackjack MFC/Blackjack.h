
#pragma once

#include <string>

class Card {

public:

	//�}�[�N�̊֐�
	static std::string cM(int ca);

	//�J�[�h�̐��̊֐�
	static char* cN(int ca2);

};


class Score {

public:

	//���Ȃ��̃J�[�h��A�̊֐�
	static bool A(int ca);

	//���Ȃ��̓��_�̊֐�
	static int YcP(int ca3);

	//�f�B�[���[�̓��_�̊֐�
	static int DcP(int ca4, int DS);

};