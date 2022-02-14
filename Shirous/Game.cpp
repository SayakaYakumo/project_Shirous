#include "Game.hpp"


void Game::update()
{
	//関数の本体は別フォルダに記述

	if (change_scene_count == 0) {//シーン変更中ではない

		switch (game_scene)
		{
		case 0://タイトル
			update_title();
			break;
		case 1://メニュー
			if (debug == 0) {
				update_menu();
			}
			else if (debug == 1) {
				update_debug_menu();
			}
			break;
		case 2://ゲーム
			update_play();
			break;
		case 3://エディタ
			update_edit();
			break;

		default:
			break;
		}

	}

	update_change_scene();

}

void Game::draw()
{
	

	switch (game_scene)
	{
	case 0://タイトル
		draw_title();
		break;
	case 1://メニュー
		if (debug == 0) {
			draw_menu();
		}
		else if (debug == 1) {
			draw_debug_menu();
		}
		break;
	case 2://ゲーム
		draw_play();
		break;
	case 3:
		draw_edit();
		break;

	default:
		break;
	}

	draw_change_scene();

}

void Game::ini(){

	///デバッグ用
	if (debug == 1) {
		load_debug();
	}

	// ウィンドウを最大化

	Scene::Resize(1920, 1080);
	Scene::SetResizeMode(ResizeMode::Keep);
	Window::SetFullscreen(true);

	//FontAsset

	FontAsset::Register(U"TitleFont", FontMethod::MSDF, 70, Typeface::Light);
	FontAsset::Load(U"TitleFont");

	FontAsset::Register(U"PoseFont", FontMethod::MSDF, 70, Typeface::Bold);
	FontAsset::Load(U"PoseFont");

	FontAsset::Register(U"ScoreFont", FontMethod::MSDF, 50, Typeface::Bold);
	FontAsset::Load(U"ScoreFont");


	// Textureアセットの登録

	//チェンジシーン
	TextureAsset::Register(U"change_scene_fade", U"data/image/ui/change_scene_fade.png");
	TextureAsset::Load(U"change_scene_fade");


	//タイトル
	TextureAsset::Register(U"title_back", U"data/image/title/back.png");
	TextureAsset::Load(U"title_back");

	//メニュー
	TextureAsset::Register(U"menu_back", U"data/image/menu/back.png");
	TextureAsset::Load(U"menu_back");

	//ポーズ
	TextureAsset::Register(U"pose_back", U"data/image/pose/back.png");
	TextureAsset::Load(U"pose_back");


	//自機
	TextureAsset::Register(U"player_シラス", U"data/image/fish/player/シラス.png");
	TextureAsset::Load(U"player_シラス");

	//ステージ１
	TextureAsset::Register(U"stage_1_back", U"data/image/back/1.png");
	TextureAsset::Load(U"stage_1_back");

	//敵
	TextureAsset::Register(U"enemy_アンモナイト", U"data/image/fish/enemy/アンモナイト.png");
	TextureAsset::Load(U"enemy_アンモナイト");

	//弾
	TextureAsset::Register(U"bullet_circle_blue_s", U"data/image/bullet/circle/blue/s.png");
	TextureAsset::Load(U"bullet_circle_blue_s");

	TextureAsset::Register(U"bullet_circle_red_s", U"data/image/bullet/circle/red/s.png");
	TextureAsset::Load(U"bullet_circle_red_s");

	//背景タイル
	TextureAsset::Register(U"back_tile", U"data/image/back/back_tile.png");
	TextureAsset::Load(U"back_tile");

	//敵サカナデータ読み込み

	/*

	for (size_t y = 0; y < 12; y++) {
		for (size_t x = 0; x < 5; x++) {

			enemy_data.push_back(Enemy_Data(U"no_data", x, y, 0, 0, 0, 0));
		}
	}*/





	// バイナリファイルをオープン
	Deserializer<BinaryReader> Ereader{ U"data/database/enemy_data.bin" };

	if (not Ereader) // もしオープンに失敗したら
	{
		throw Error{ U"Failed to open `tutorial4.bin`" };
	}

	
	// バイナリファイルからシリアライズ対応型のデータを読み込む
	// （Array は自動でリサイズが行われる）
	Ereader(enemy_data);




/*
	// バイナリファイルをオープン
	Serializer<BinaryWriter> Swriter{ U"save_data/save_data.bin" };

	if (not Swriter) // もしオープンに失敗したら
	{
		throw Error{ U"Failed to open `tutorial4.bin`" };
	}

	// シリアライズに対応したデータを記録
	Swriter(save_data);*/







	/**/

	//セーブデータ読み込み

	// バイナリファイルをオープン
	Deserializer<BinaryReader> Sreader{ U"save_data/save_data.bin" };

	if (not Sreader) // もしオープンに失敗したら
	{
		throw Error{ U"Failed to open `tutorial4.bin`" };
	}

	// バイナリファイルからシリアライズ対応型のデータを読み込む
	// （Array は自動でリサイズが行われる）
	Sreader(save_data);
}








