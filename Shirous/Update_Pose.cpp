#include"Game.hpp"

void Game::update_pose() {

	if (KeyControl.down()) {
		play_scene = 0;//ゲームにもどる
	}

	if (debug == 1) {//デバッグ中はメニューへバック
		if (KeyZ.down()) {
			game_scene = 1;
			play_scene = 0;
		}
	}
}
