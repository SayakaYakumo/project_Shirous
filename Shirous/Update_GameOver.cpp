#include"Game.hpp"

void Game::update_gameover() {

	if (KeyA.down())
	{
		effect.clear();
		gamePlayer.first();
		gameEnemys.clear();
		gamePlayerBullet.clear();
		gameEnemyBullet.clear();
		highScore = Max(highScore, score);
		score = 0;
	}
}
