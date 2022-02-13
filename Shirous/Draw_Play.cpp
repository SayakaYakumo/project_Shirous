#include"Game.hpp"

void Game::draw_play()
{
	switch (play_scene)
	{
	case 0://ゲーム
		draw_main();
		break;
	case 1://ポーズ
		draw_main();//ゲームの上に描画しますので
		draw_pose();
		break;
	case 2://ゲームオーバー
		draw_gameover();
		break;
	default:
		break;
	}



}

