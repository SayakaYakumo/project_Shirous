/*
#include "Game.hpp"

Game::Game(const InitData& init)
	: IScene{ init }
{

	font = Font(30);
	gameoverfont = Font(60);

	//プレイヤーの生成
	gamePlayer = Player();

}

void Game::update()
{
	//関数の本体は別フォルダに記述

	switch (game_scene)
	{
	case 0://データ読み込み
		update_first();
		game_scene = 1;//ゲームへ移行
		break;
	case 1://ゲーム
		update_main();
		break;
	case 2://ポーズ
		update_pose();
		break;
	case 3://ゲームオーバー
		update_gameover();
		break;
	default:
		break;
	}


}

void Game::draw() const
{


	switch (game_scene)
	{
	case 0://読み込み部では描画しない
		break;
	case 1://ゲーム
		draw_main();
		break;
	case 2://ポーズ
		draw_pose();
		break;
	case 3://ゲームオーバー
		draw_gameover();
		break;
	default:
		break;
	}



}*/








