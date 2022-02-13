#include"Game.hpp"

void Game::draw_main() const {

	draw_main_back();//背景描画

	draw_enemy();//敵描画

	draw_player();//自機描画

	draw_bullet();//弾描画

	effect.update();//エフェクト描画
}

void Game::draw_main_back() const {

	//仮おき背景
	switch (stage_number)
	{
	case 0:
		TextureAsset(U"stage_0_back").draw(0, 0);
		break;
	case 1:
		TextureAsset(U"stage_1_back").draw(0, 0);
		break;
	case 2:
		TextureAsset(U"stage_2_back").draw(0, 0);
		break;
	case 3:
		TextureAsset(U"stage_3_back").draw(0, 0);
		break;
	case 4:
		TextureAsset(U"stage_4_back").draw(0, 0);
		break;
	case 5:
		TextureAsset(U"stage_5_back").draw(0, 0);
		break;
	case 6:
		TextureAsset(U"stage_6_back").draw(0, 0);
		break;
	case 7:
		TextureAsset(U"stage_7_back").draw(0, 0);
		break;
	case 8:
		TextureAsset(U"stage_8_back").draw(0, 0);
		break;
	case 9:
		TextureAsset(U"stage_9_back").draw(0, 0);
		break;
	default:
		break;
	}

	for (size_t i = 0; i < back_tile.size(); i++) {
		if (back_tile[i].get_kind() != -1) {
			back_tile[i].draw(stage_scroll);
		}
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
