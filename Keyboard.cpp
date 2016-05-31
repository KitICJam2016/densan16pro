//------------------------------------------------------------------------------
/// @file
/// @brief    Keyboard.hpp�̎���
/// @author   ��`�ĕ�
///
/// @copyright  Copyright 2016 ��`�ĕ�

//------------------------------------------------------------------------------

#include "DxLib.h"
#include "Keyboard.hpp"


static int m_Key[256];			  // �L�[�̓��͏�Ԋi�[�p�ϐ�
static int n_Key[256];


// �L�[�̓��͏�ԍX�V
void Keyboard_Update()
{

	char tmpKey[256];             // ���݂̃L�[�̓��͏�Ԃ��i�[����
	GetHitKeyStateAll(tmpKey);    // �S�ẴL�[�̓��͏�Ԃ𓾂�

	for (int i = 0; i < 256; i++)
	{
		if (tmpKey[i] != 0)     // i�Ԃ̃L�[�R�[�h�ɑΉ�����L�[��������Ă�����
			m_Key[i]++;         // ���Z
		else                    // ������Ă��Ȃ����
			m_Key[i] = 0;       // 0�ɂ���
	}
}


// KeyCode�̃L�[�̓��͏�Ԃ��擾����
int Keyboard_Get(int KeyCode){
	return m_Key[KeyCode];		  // KeyCode�̓��͏�Ԃ�Ԃ�
}
