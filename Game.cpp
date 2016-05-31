#include "DxLib.h"

#include "Game.hpp"


Game::Game(ISceneChanger * changer)
	:	BaseScene(changer)
{
}

Game::~Game()
{
}

void Game::Update()
{
}

void Game::Draw()
{
	DrawFormatString(20, 20, GetColor(0, 255, 0), "NOW_GAME_SCENE");
}
// EOF
