#include "DxLib.h"

#include "SceneMng.hpp"
#include "Keyboard.hpp"

#include "Game.hpp"
#include "Menu.hpp"


SceneMng::SceneMng() : mNextScene(eScene_None) {		// ���̃V�[���Ǘ��ϐ�
	mScene = static_cast<BaseScene*> (new Menu(this));	// �ŏ��̃V�[��
}


SceneMng::~SceneMng()
{
	delete mScene;
}


//�X�V
void SceneMng::Update()
{
	if (mNextScene != eScene_None)								// ���̃V�[�����Z�b�g����Ă�����
	{
		delete mScene;											// ���݂̃V�[���̏I�����������s
		switch (mNextScene)										// �V�[���ɂ���ď����𕪊�
		{
		case eScene_Menu:										// ���̉�ʂ����j���[�Ȃ�
			mScene = static_cast<BaseScene*> (new Menu(this));	// ���j���[��ʂ̃C���X�^���X�𐶐�����
			break;												// �ȉ���
		case eScene_Game:
			mScene = static_cast<BaseScene*> (new Game(this));
			break;
		}
		mNextScene = eScene_None;								// ���̃V�[�������N���A
	}
	mScene->Update();											// �V�[���̍X�V
}


//�`��
void SceneMng::Draw() { mScene->Draw(); }


// ���� nextScene �ɃV�[����ύX����
void SceneMng::ChangeScene(eScene NextScene) { mNextScene = NextScene; }	// ���̃V�[�����Z�b�g