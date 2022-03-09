#include"Game.hpp"

void Game::update_gameover() {

	if (KeyA.down())
	{
		effect.clear();
		gamePlayer->start();
		gameEnemys.clear();
		gamePlayerBullet.clear();
		gameEnemyBullet.clear();
		highScore = Max(highScore, score);
		score = 0;
	}
}
