#include"Game.hpp"

void Game::draw_main() const {

	draw_main_back();//背景描画

	draw_enemy();//敵描画

	draw_player();//自機描画

	draw_bullet();//弾描画

	effect.update();//エフェクト描画
}

void Game::draw_main_back() const {

	switch (stage_number)
	{
	case 0:
		
		break;
	case 1:
		TextureAsset(U"stage_1_back").draw(0, 0);
		break;
	case 2:
		break;
	case 3:
		break;
	case 4:
		break;
	case 5:
		break;
	case 6:
		break;
	default:
		break;
	}

}


void Game::draw_enemy() const{

	for (size_t i = 0; i < gameEnemys.size(); i++) {
		gameEnemys[i].Draw();
	}
}


void Game::draw_player() const{

	gamePlayer.Draw();
}

void Game::draw_bullet()const {

	for (size_t i = 0; i < gamePlayerBullet.size(); i++) {
		gamePlayerBullet[i].Draw();
	}

	for (size_t i = 0; i < gameEnemyBullet.size(); i++) {
		gameEnemyBullet[i].Draw();
	}

}
