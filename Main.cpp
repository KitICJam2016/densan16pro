//------------------------------------------------------------------------------
/// @file
/// @brief    メイン

//------------------------------------------------------------------------------

#include "DxLib.h"

#include "Keyboard.hpp"
#include "SceneMng.hpp"

#include <time.h>
#include <memory>


static int FrameStartTime;
static int FPS_60		= 1000 / 60;
static bool isFullSc	= false;
static bool isPlay		= true;

// @brief		画面設定に関しての質問
// @attention	キャンセルでウィンドウモードのまま
static void message_box();

// @brief	60fpsを保たせる処理
static void FPSMng();

// @brief	ウィンドウ初期設定
static void Initialize();

// @brief	いつでも受け付ける設定
static void DynamicConfig();


// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	Initialize();
	std::unique_ptr<SceneMng>	sceneMng(new SceneMng);

	// ゲーム--------------------------------------------------------------------------------------
	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0 && isPlay)
	{
		FPSMng();
		Keyboard_Update();										// キー入力状況更新
		DynamicConfig();
		sceneMng->Update();
		sceneMng->Draw();
	}
	DxLib_End();												// ＤＸライブラリ使用の終了処理
	return 0;
}


void message_box()
{
	int flag;

	flag = MessageBox(
		NULL,
		TEXT("フルスクリーンモードで起動しますか？\n（F5でいつでも変更可能です。）"),
		TEXT("スクリーン設定"),
		MB_YESNOCANCEL | MB_ICONQUESTION);

	if (flag == IDNO)
	{
		isFullSc = true;
		//		SetUseBackBufferTransColorFlag(true); // 全部透明化フラグ
	}
}


void FPSMng()
{
	while (GetNowCount() - FrameStartTime < FPS_60) {}		// 1/60 秒まで待つ
	FrameStartTime = GetNowCount();							// 現在のカウントを保存
}


void Initialize()
{
	message_box();
	SetGraphMode(640, 480, 32), ChangeWindowMode(isFullSc), DxLib_Init();						// ウィンドウ初期設定(VGA),DxLib起動
	SetDrawScreen(DX_SCREEN_BACK);																// 裏画面処理
	SetMainWindowText("演習");																	// タイトルを設定
	SetChangeScreenModeGraphicsSystemResetFlag(FALSE);											// 画面モード変更後、素材メモリをリセットしない
	SetEmulation320x240(TRUE);																	// 320x240の解像度にする
	SetWaitVSyncFlag(FALSE);																	// 垂直同期信号を待たない
	FrameStartTime = GetNowCount();																// 開始時間を設定
	SRand((unsigned)time(NULL));																// 乱数シード
}


void DynamicConfig()
{
	// 画面モード変更
	if (Keyboard_Get(KEY_INPUT_F5) == 1)		ChangeWindowMode(isFullSc = !isFullSc);

	// メインループを抜ける
	if (Keyboard_Get(KEY_INPUT_ESCAPE) == 1)	isPlay = false;
}
// EOF
