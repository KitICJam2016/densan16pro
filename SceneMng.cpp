#include "DxLib.h"

#include "SceneMng.hpp"
#include "Keyboard.hpp"

#include "Game.hpp"
#include "Menu.hpp"


SceneMng::SceneMng() : mNextScene(eScene_None) {		// 次のシーン管理変数
	mScene = static_cast<BaseScene*> (new Menu(this));	// 最初のシーン
}


SceneMng::~SceneMng()
{
	delete mScene;
}


//更新
void SceneMng::Update()
{
	if (mNextScene != eScene_None)								// 次のシーンがセットされていたら
	{
		delete mScene;											// 現在のシーンの終了処理を実行
		switch (mNextScene)										// シーンによって処理を分岐
		{
		case eScene_Menu:										// 次の画面がメニューなら
			mScene = static_cast<BaseScene*> (new Menu(this));	// メニュー画面のインスタンスを生成する
			break;												// 以下略
		case eScene_Game:
			mScene = static_cast<BaseScene*> (new Game(this));
			break;
		}
		mNextScene = eScene_None;								// 次のシーン情報をクリア
	}
	mScene->Update();											// シーンの更新
}


//描画
void SceneMng::Draw() { mScene->Draw(); }


// 引数 nextScene にシーンを変更する
void SceneMng::ChangeScene(eScene NextScene) { mNextScene = NextScene; }	// 次のシーンをセット