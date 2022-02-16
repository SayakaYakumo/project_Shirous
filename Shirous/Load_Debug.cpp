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

	//デバッグメニューフォント5
	FontAsset::Register(U"DebugMenuFont5", FontMethod::MSDF, 35, Typeface::Bold);
	FontAsset::Load(U"DebugMenuFont5");

	//デバッグメニューフォント6
	FontAsset::Register(U"DebugMenuFont6", FontMethod::MSDF, 70, Typeface::Bold);
	FontAsset::Load(U"DebugMenuFont6");

	//デバッグメニューフォント7
	FontAsset::Register(U"DebugMenuFont7", FontMethod::MSDF, 50, Typeface::Bold);
	FontAsset::Load(U"DebugMenuFont7");

	//デバッグメニューフォント7
	FontAsset::Register(U"DebugMenuFont8", FontMethod::MSDF, 120, Typeface::Bold);
	FontAsset::Load(U"DebugMenuFont8");

	//メニュー用
	TextureAsset::Register(U"debug_menu_rect_frame", U"data/image/debug/menu_rect_frame.png");
	TextureAsset::Load(U"debug_menu_rect_frame");

	TextureAsset::Register(U"debug_menu_rect_frame_mini", U"data/image/debug/menu_rect_frame_mini.png");
	TextureAsset::Load(U"debug_menu_rect_frame_mini");

	TextureAsset::Register(U"debug_menu_rect_frame_mini_select", U"data/image/debug/menu_rect_frame_mini_select.png");
	TextureAsset::Load(U"debug_menu_rect_frame_mini_select");

	TextureAsset::Register(U"debug_menu_rect_frame_mini_2", U"data/image/debug/menu_rect_frame_mini_2.png");
	TextureAsset::Load(U"debug_menu_rect_frame_mini_2");

	TextureAsset::Register(U"debug_menu_rect_frame_mini_2_select", U"data/image/debug/menu_rect_frame_mini_2_select.png");
	TextureAsset::Load(U"debug_menu_rect_frame_mini_2_select");

	TextureAsset::Register(U"debug_menu_rect_frame_enemy", U"data/image/debug/menu_rect_frame_enemy.png");
	TextureAsset::Load(U"debug_menu_rect_frame_enemy");

	TextureAsset::Register(U"debug_menu_rect_select_frame", U"data/image/debug/menu_rect_select_frame.png");
	TextureAsset::Load(U"debug_menu_rect_select_frame");

	TextureAsset::Register(U"debug_menu_rect_database_frame", U"data/image/debug/menu_rect_database_frame.png");
	TextureAsset::Load(U"debug_menu_rect_database_frame");

	TextureAsset::Register(U"debug_menu_rect_database_select_frame", U"data/image/debug/menu_rect_database_frame.png");
	TextureAsset::Load(U"debug_menu_rect_database_select_frame");

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

	//エディタのダーク
	TextureAsset::Register(U"debug_edit_dark", U"data/image/debug/edit_dark.png");
	TextureAsset::Load(U"debug_edit_dark");

	//エディタツールボックスミニ(没)
	TextureAsset::Register(U"debug_edit_enemy_tool", U"data/image/debug/edit_enemy_tool.png");
	TextureAsset::Load(U"debug_edit_enemy_tool");

	//エディタの当たり判定の四角形の設置
	TextureAsset::Register(U"debug_edit_plus_hit_rect", U"data/image/debug/plus_hit_rect.png");
	TextureAsset::Load(U"debug_edit_plus_hit_rect");

	//エディタの当たり判定の四角形の削除
	TextureAsset::Register(U"debug_edit_back_hit_rect", U"data/image/debug/back_hit_rect.png");
	TextureAsset::Load(U"debug_edit_back_hit_rect");
	
	//エディタの弾出し位置
	TextureAsset::Register(U"debug_edit_plus_center", U"data/image/debug/plus_center.png");
	TextureAsset::Load(U"debug_edit_plus_center");

	//エディタの情報
	TextureAsset::Register(U"debug_edit_information", U"data/image/debug/information.png");
	TextureAsset::Load(U"debug_edit_information");

	//エディタの敵追加
	TextureAsset::Register(U"debug_edit_plus_fish", U"data/image/debug/plus_fish.png");
	TextureAsset::Load(U"debug_edit_plus_fish");

	//エディタの敵削除
	TextureAsset::Register(U"debug_edit_minus_fish", U"data/image/debug/minus_fish.png");
	TextureAsset::Load(U"debug_edit_minus_fish");

}
