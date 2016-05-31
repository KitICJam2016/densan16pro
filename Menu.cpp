#include "Menu.hpp"
#include "DxLib.h"


Menu::Menu(ISceneChanger * changer)
	: BaseScene(changer)
	, gh_title(LoadGraph("Image/nita_title.png"))
{
}


Menu::~Menu()
{
	DeleteGraph(gh_title);
}


void Menu::Update()
{
	if (Keyboard_Get(KEY_INPUT_Z) == 1)	mSceneChanger->ChangeScene(eScene_Game);
}


void Menu::Draw()
{
	DrawRotaGraph(320, 240, 2.0, 0.0, gh_title, true);
	DrawFormatString(260, 280, GetColor(255, 255, 255), "PRESS Z KEY");
}
//EOF