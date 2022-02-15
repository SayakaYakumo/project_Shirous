﻿#include"Game.hpp"

void Game::play_load(int stage_number) {

	switch (stage_number)
	{
	case 0:
		stage_0_load();
		break;
	case 1:
		stage_1_load();
		break;
	case 2:
		stage_2_load();
		break;
	case 3:
		stage_3_load();
		break;
	case 4:
		stage_4_load();
		break;
	case 5:
		stage_5_load();
		break;
	case 6:
		stage_6_load();
		break;
	case 7:
		stage_7_load();
		break;
	case 8:
		stage_8_load();
		break;
	case 9:
		stage_9_load();
		break;
	default:
		break;
	}

}


void Game::stage_0_load() {

	/**/
	
	


	/*
	for (int x = 0; x < 16; x++) {
		for (int y = 0; y < 9; y++) {
			back_tile.push_back(Back_Tile(x, y, 1));
		}
	}
*/

	

	//背景データ

	
	Deserializer<BinaryReader> reader{ U"data/stage/0/BackTile.bin" };

	if (not reader)
	{
		throw Error{ U"Failed to open `tutorial4.bin`" };
	}

	reader(back_tile);

    //敵生成データ


	Deserializer<BinaryReader> EEreader{ U"data/stage/0/emerge_enemy.bin" };

	if (not EEreader)
	{
		throw Error{ U"Failed to open `tutorial4.bin`" };
	}

	EEreader(emergeEnemys);



	// アセットの登録

	//ステージ0の登録
	TextureAsset::Register(U"stage_0_back", U"data/image/back/0.png");
	TextureAsset::Load(U"stage_0_back");

	//敵の登録
	TextureAsset::Register(U"enemy_アンモナイト", U"data/image/fish/enemy/アンモナイト.png");
	TextureAsset::Load(U"enemy_アンモナイト");

	//弾の登録
	TextureAsset::Register(U"bullet_circle_blue_s", U"data/image/bullet/circle/blue/s.png");
	TextureAsset::Load(U"bullet_circle_blue_s");

	TextureAsset::Register(U"bullet_circle_red_s", U"data/image/bullet/circle/red/s.png");
	TextureAsset::Load(U"bullet_circle_red_s");

	TextureAsset::Register(U"back_tile", U"data/image/back/back_tile.png");
	TextureAsset::Load(U"back_tile");
	
	//Item
	TextureAsset::Register(U"item_赤", U"data/image/item/赤.png");
	TextureAsset::Load(U"item_赤");

	TextureAsset::Register(U"item_青", U"data/image/item/青.png");
	TextureAsset::Load(U"item_青");

	TextureAsset::Register(U"item_緑", U"data/image/item/緑.png");
	TextureAsset::Load(U"item_緑");

}

void Game::stage_1_load() {

}

void Game::stage_2_load() {

}

void Game::stage_3_load() {

}

void Game::stage_4_load() {

}

void Game::stage_5_load() {

}

void Game::stage_6_load() {

}

void Game::stage_7_load() {

}

void Game::stage_8_load() {

}

void Game::stage_9_load() {

}