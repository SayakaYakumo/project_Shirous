#include"Game.hpp"

void Game::load_debug() {

	//デバッグメニューフォント
	FontAsset::Register(U"DebugMenuFont", FontMethod::MSDF, 40, Typeface::Light);
	FontAsset::Load(U"DebugMenuFont");

	//デバッグメニューフォント2
	FontAsset::Register(U"DebugMenuFont2", FontMethod::MSDF, 100, Typeface::Bold);
	FontAsset::Load(U"DebugMenuFont2");

	//デバッグメニューフォント3
	FontAsset::Register(U"DebugMenuFont3", FontMethod::MSDF, 120, Typeface::Bold);
	FontAsset::Load(U"DebugMenuFont3");

	//デバッグメニューフォント4
	FontAsset::Register(U"DebugMenuFont4", FontMethod::MSDF, 60, Typeface::Bold);
	FontAsset::Load(U"DebugMenuFont4");


	//メニュー用
	TextureAsset::Register(U"debug_menu_rect_frame", U"data/image/debug/menu_rect_frame.png");
	TextureAsset::Load(U"debug_menu_rect_frame");

	TextureAsset::Register(U"debug_menu_rect_select_frame", U"data/image/debug/menu_rect_select_frame.png");
	TextureAsset::Load(U"debug_menu_rect_select_frame");

	//エディタのリスト
	TextureAsset::Register(U"debug_edit_list", U"data/image/debug/edit_list.png");
	TextureAsset::Load(U"debug_edit_list");

	//エディタのバック
	TextureAsset::Register(U"debug_edit_back", U"data/image/debug/back.png");
	TextureAsset::Load(U"debug_edit_back");

	//エディタのペン
	TextureAsset::Register(U"debug_edit_select", U"data/image/debug/edit_select.png");
	TextureAsset::Load(U"debug_edit_select");

	//エディタのペン
	TextureAsset::Register(U"debug_edit_pen", U"data/image/debug/pen.png");
	TextureAsset::Load(U"debug_edit_pen");

	//エディタの消しゴム
	TextureAsset::Register(U"debug_edit_eraser", U"data/image/debug/eraser.png");
	TextureAsset::Load(U"debug_edit_eraser");

	//エディタのバケツ
	TextureAsset::Register(U"debug_edit_bukket", U"data/image/debug/bukket.png");
	TextureAsset::Load(U"debug_edit_bukket");

	//エディタのバケツ消しゴム
	TextureAsset::Register(U"debug_edit_bukket_erase", U"data/image/debug/bukket_erase.png");
	TextureAsset::Load(U"debug_edit_bukket_erase");

	//エディタのセーブ
	TextureAsset::Register(U"debug_edit_save", U"data/image/debug/save.png");
	TextureAsset::Load(U"debug_edit_save");

}
