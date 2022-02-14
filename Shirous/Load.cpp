#include"Game.hpp"

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
	
	//敵生成データ

	const CSV csv_EMERGE_ENEMY(U"data/stage/0/EmergeEnemy.csv");
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

	
	for (int x = 0; x < 16; x++) {
		for (int y = 0; y < 9; y++) {
			back_tile.push_back(Back_Tile(x, y, 1));
		}
	}


	
/**/
	//背景データ

	// バイナリファイルをオープン
	Deserializer<BinaryReader> reader{ U"data/stage/0/BackTile.bin" };

	if (not reader) // もしオープンに失敗したら
	{
		throw Error{ U"Failed to open `tutorial4.bin`" };
	}

	// バイナリファイルからシリアライズ対応型のデータを読み込む
	// （Array は自動でリサイズが行われる）
	reader(back_tile);


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
