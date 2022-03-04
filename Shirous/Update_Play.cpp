#include"Game.hpp"

void Game::update_play() {

		//関数の本体は別フォルダに記述

		switch (play_scene)
		{
		case 0://ゲーム
			update_main();
			break;
		case 1://ポーズ
			update_pose();
			break;
		case 2://ゲームオーバー
			update_gameover();
			break;
		default:
			break;
		}


	
}
