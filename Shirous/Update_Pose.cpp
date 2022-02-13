#include"Game.hpp"

void Game::update_pose() {

	if (KeyControl.down()) {
		play_scene = 0;//ゲームにもどる
	}
}
