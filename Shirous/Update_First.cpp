#include"Game.hpp"

void Game::update_first() {

	switch (stage_number)
	{
	case 0:
		
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
	default:
		break;
	}

}


void Game::stage_1_load() {

	/**/
	
	//敵生成データ

	const CSV csv_EMERGE_ENEMY(U"data/stage/1/EmergeEnemy.csv");
	if (not csv_EMERGE_ENEMY) {
		throw Error(U"Failed to load 'magic_data.csv'");
	}



	//縦
	for (int y = 0; y < csv_EMERGE_ENEMY.rows() - 1; y++) {

		String name = U"no_data";
		int pos_x = 0;
		int pos_y = 0;
		int move = 0;
		int shot_pattern = 0;
		int time = 0;

		//横
		for (int x = 0; x < 6; x++) {

			switch (x)
			{
			case 0:
				name = Parse<String>(csv_EMERGE_ENEMY[y + 1][x]);
				break;
			case 1:
				pos_x = Parse<int>(csv_EMERGE_ENEMY[y + 1][x]);
				break;
			case 2:
				pos_y = Parse<int>(csv_EMERGE_ENEMY[y + 1][x]);
				break;
			case 3:
				move = Parse<int>(csv_EMERGE_ENEMY[y + 1][x]);
				break;
			case 4:
				shot_pattern = Parse<int>(csv_EMERGE_ENEMY[y + 1][x]);
				break;
			case 5:
				time = Parse<int>(csv_EMERGE_ENEMY[y + 1][x]);
				break;
			}

		}

		emergeEnemys.push_back(EmergeEnemy(name, pos_x, pos_y, move,shot_pattern,time));

	}


	//背景データ

	const CSV csv_BACK_TILE(U"data/stage/1/Back_Tile.csv");
	if (not csv_EMERGE_ENEMY) {
		throw Error(U"Failed to load 'magic_data.csv'");
	}




	//縦
	for (int y = 0; y < csv_BACK_TILE.rows(); y++) {

		int pos_x = 0;
		int pos_y = 0;
		int kind = 0;

		//横
		for (int x = 0; x < 65; x++) {
			kind = Parse<int>(csv_BACK_TILE[y][x]);
			back_tile.push_back(Back_Tile(x,y,kind));

		}

	}






	// アセットの登録

	//自機の登録
	TextureAsset::Register(U"player_シラス", U"data/image/fish/player/シラス.png");
	TextureAsset::Load(U"player_シラス");

	//ステージ１の登録
	TextureAsset::Register(U"stage_1_back", U"data/image/back/1.png");
	TextureAsset::Load(U"stage_1_back");

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
