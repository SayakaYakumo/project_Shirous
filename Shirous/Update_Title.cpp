#include"Game.hpp"

void Game::update_title() {

	if (KeyZ.down()) {//Menuシーンへ
		change_scene(1);
	}
	else if (debug == 1) {//デバッグ中はクリックでも可
		if (MouseL.down()) {
			game_scene = 1;
		}
	}
	
}
