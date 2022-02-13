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
			update_menu();
			break;
		case 2://ゲーム
			update_play();
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
		draw_menu();
		break;
	case 2://ゲーム
		draw_play();
		break;

	default:
		break;
	}

	draw_change_scene();

}

void Game::ini(){

	// ウィンドウを最大化

	Scene::Resize(1920, 1080);
	Scene::SetResizeMode(ResizeMode::Keep);
	Window::SetFullscreen(true);

	//FontAsset

	FontAsset::Register(U"TitleFont", FontMethod::MSDF, 70, Typeface::Light);
	FontAsset::Load(U"TitleFont");

	FontAsset::Register(U"PoseFont", FontMethod::MSDF, 70, Typeface::Bold);
	FontAsset::Load(U"PoseFont");


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

	TextureAsset::Register(U"back_tile", U"data/image/back/back_tile.png");
	TextureAsset::Load(U"back_tile");



}








