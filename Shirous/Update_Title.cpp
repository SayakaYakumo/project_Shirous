#include"Game.hpp"

void Game::update_title() {

	if (KeyZ.down()) {//Menuシーンへ
		change_scene(1);
	}
}
