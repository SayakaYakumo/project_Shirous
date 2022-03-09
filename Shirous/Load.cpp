#include"Game.hpp"

void Game::play_load(int stage_number) {

	back_tile.clear();//データ初期化
	emergeEnemys.clear();//データ初期化

	gamePlayer->start();
	gamePlayerBullet.clear();
	gameEnemys.clear();
	gameEnemyBullet.clear();

	stage_scroll = 0;
	stage_time = 0;
	

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

	//ステージデータ
	Deserializer<BinaryReader> Sreader{ U"data/stage/0/Stage_Data.bin" };

	if (not Sreader)
	{
		throw Error{ U"Failed to open `tutorial4.bin`" };
	}

	Sreader(stage_data);

	stage_speed = stage_data.get_speed();
	stage_wide = stage_data.get_wide();
	/**/
	
	


	/*
	for (int x = 0; x < 16; x++) {
		for (int y = 0; y < 9; y++) {
			back_tile.push_back(Back_Tile(x, y, 1));
		}
	}


	

	//背景データ

	
	Deserializer<BinaryReader> Breader{ U"data/stage/0/BackTile.bin" };

	if (not Breader)
	{
		throw Error{ U"Failed to open `tutorial4.bin`" };
	}

	Breader(back_tile);*/

    //敵生成データ

	/*
	Deserializer<BinaryReader> EEreader{ U"data/stage/0/emerge_enemy.bin" };

	if (not EEreader)
	{
		throw Error{ U"Failed to open `tutorial4.bin`" };
	}

	EEreader(emergeEnemys);
*/


//Enemyデータ

	const CSV csv_ED(U"data/stage/0/emerge_enemy.csv");
	if (!csv_ED) {
		throw Error(U"Failed to load 'magic_data.csv'");
	}

	//縦
	for (int y = 0; y < csv_ED.rows() - 1; y++) {

	String name = U"no_data";
		String name2 = U"no_data";
		int x_pos = 0;
		int y_pos = 0;
		double time = 0;

		//横
		for (int x = 0; x < 5; x++) {

			switch (x)
			{
			case 0:
				name = Parse<String>(csv_ED[y + 1][x]);
				break;
			case 1:
				name2 = Parse<String>(csv_ED[y + 1][x]);
				break;
			case 2:
				x_pos = Parse<int>(csv_ED[y + 1][x]);
				break;
			case 3:
				y_pos = Parse<int>(csv_ED[y + 1][x]);
				break;
			case 4:
				time=Parse<double>(csv_ED[y + 1][x]);
				break;
			
			default:
				break;
			}

		}

		emergeEnemys.push_back(EmergeEnemy(name,name2,x_pos,y_pos,time));
		
	}


	// アセットの登録

	//ステージ0の登録
	TextureAsset::Register(U"stage_0_back", U"data/image/back/0.png");
	TextureAsset::Load(U"stage_0_back");

	


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
