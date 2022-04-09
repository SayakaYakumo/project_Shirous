#include"Game.hpp"

void Game::draw_main() const {

	draw_main_back();//背景描画

	draw_enemy();//敵描画

	draw_player();//自機描画

	draw_bullet();//弾描画

	draw_item();//アイテム描画

	effect.update();//エフェクト描画

	draw_my_effect();//マイエフェクト描画

	draw_ui();//UI描画

	
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

	if (debug_play == 1) {//デバッグ中
		for (size_t i = 0; i < gameEnemys.size(); i++) {
			gameEnemys[i].DrawFrame();
		}

	}
}


void Game::draw_player() const{

	gamePlayer.Draw();

	if (debug_play == 1) {
		gamePlayer.DrawFrame();
	}
}

void Game::draw_bullet()const {

	for (size_t i = 0; i < gamePlayerBullet.size(); i++) {
		gamePlayerBullet[i].Draw();
		if (debug_play == 1) {
			gamePlayerBullet[i].Draw_Frame();
		}
	}

	for (size_t i = 0; i < gameEnemyBullet.size(); i++) {
		gameEnemyBullet[i].Draw();
		if (debug_play == 1) {
			gameEnemyBullet[i].Draw_Frame();
		}
	}

	//ボム
	bomb->Draw();
}

void Game::draw_item()const {
	for (size_t i = 0; i < gameItems.size(); i++) {
		gameItems[i].Draw();
	}
}

void Game::draw_ui()const {

	double _fade = 1;

	if (gamePlayer.get_rect().y < 400) {
		_fade = 1 * (abs(200 - gamePlayer.get_rect().y) / double(200));

		if (gamePlayer.get_rect().y <= 200) {
			_fade = 0;
		}
	}


	FontAsset(U"ScoreFont")(U"SCORE : {:0>12}"_fmt(score)).draw(100, 10,ColorF(1.0,_fade));
	FontAsset(U"ScoreFont")(U"BOMB  : {:0>2}"_fmt(bomb->getBombNum())).draw(100, 80, ColorF(1.0, _fade));
	FontAsset(U"ScoreFont")(U"LIFE  : {}"_fmt(gamePlayer.get_hp())).draw(1920/4 + 100, 80, ColorF(1.0, _fade));
	FontAsset(U"ScoreFont")(U"HISCORE : {:0>12}"_fmt(highScore)).draw((1920 / 2) + 100, 10,ColorF(1.0,_fade));

	double feed = gamePlayer.get_feed();
	double useFeed = gamePlayer.get_use_feed();
	RectF(1920 / 2 + 100, 90, 720, 60).draw(Palette::Gray);
	RectF(1920 / 2 + 100, 90, 720.0 * (feed / 100.0), 60).draw(Palette::Lightgreen);
	RectF(1920 / 2 + 100 + 720.0 * ((feed - useFeed) / 100.0), 90, 720.0 * (useFeed / 100.0), 60).draw(Palette::Orangered);

	
}

void Game::draw_my_effect() const{

	for (size_t m = 0; m < my_effect.size(); m++) {
		my_effect[m].draw();
	}
}
