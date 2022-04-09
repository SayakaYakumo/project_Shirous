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
	TextureAsset::Register(U"debug_menu_rect_frame", U"data/image/debug_test/menu_rect_frame.png");
	TextureAsset::Load(U"debug_menu_rect_frame");

	TextureAsset::Register(U"debug_menu_rect_frame_mini", U"data/image/debug_test/menu_rect_frame_mini.png");
	TextureAsset::Load(U"debug_menu_rect_frame_mini");

	TextureAsset::Register(U"debug_menu_rect_frame_mini_select", U"data/image/debug_test/menu_rect_frame_mini_select.png");
	TextureAsset::Load(U"debug_menu_rect_frame_mini_select");

	TextureAsset::Register(U"debug_menu_rect_frame_mini_2", U"data/image/debug_test/menu_rect_frame_mini_2.png");
	TextureAsset::Load(U"debug_menu_rect_frame_mini_2");

	TextureAsset::Register(U"debug_menu_rect_frame_mini_2_select", U"data/image/debug_test/menu_rect_frame_mini_2_select.png");
	TextureAsset::Load(U"debug_menu_rect_frame_mini_2_select");

	TextureAsset::Register(U"debug_menu_rect_frame_enemy", U"data/image/debug_test/menu_rect_frame_enemy.png");
	TextureAsset::Load(U"debug_menu_rect_frame_enemy");

	TextureAsset::Register(U"debug_menu_rect_select_frame_enemy", U"data/image/debug_test/menu_rect_select_frame_enemy.png");
	TextureAsset::Load(U"debug_menu_rect_select_frame_enemy");

	TextureAsset::Register(U"debug_menu_rect_select_frame", U"data/image/debug_test/menu_rect_select_frame.png");
	TextureAsset::Load(U"debug_menu_rect_select_frame");

	TextureAsset::Register(U"debug_menu_rect_database_frame", U"data/image/debug_test/menu_rect_database_frame.png");
	TextureAsset::Load(U"debug_menu_rect_database_frame");

	TextureAsset::Register(U"debug_menu_rect_database_select_frame", U"data/image/debug_test/menu_rect_database_frame.png");
	TextureAsset::Load(U"debug_menu_rect_database_select_frame");

	TextureAsset::Register(U"debug_number_botton", U"data/image/debug_test/number_button.png");
	TextureAsset::Load(U"debug_number_botton");

	TextureAsset::Register(U"debug_number_botton_select", U"data/image/debug_test/number_button_select.png");
	TextureAsset::Load(U"debug_number_botton_select");

	TextureAsset::Register(U"debug_number_input", U"data/image/debug_test/number_input.png");
	TextureAsset::Load(U"debug_number_input");

	TextureAsset::Register(U"debug_number_input_select", U"data/image/debug_test/number_input_select.png");
	TextureAsset::Load(U"debug_number_input_select");

	TextureAsset::Register(U"debug_number_input_back", U"data/image/debug_test/number_input_back.png");
	TextureAsset::Load(U"debug_number_input_back");

	TextureAsset::Register(U"debug_number_input_back_select", U"data/image/debug_test/number_input_back_select.png");
	TextureAsset::Load(U"debug_number_input_back_select");

	TextureAsset::Register(U"debug_number_input_minus", U"data/image/debug_test/number_input_minus.png");
	TextureAsset::Load(U"debug_number_input_minus");

	TextureAsset::Register(U"debug_number_input_minus_select", U"data/image/debug_test/number_input_minus_select.png");
	TextureAsset::Load(U"debug_number_input_minus_select");

	TextureAsset::Register(U"debug_number_input_end", U"data/image/debug_test/number_input_end.png");
	TextureAsset::Load(U"debug_number_input_end");

	TextureAsset::Register(U"debug_number_input_end_select", U"data/image/debug_test/number_input_end_select.png");
	TextureAsset::Load(U"debug_number_input_end_select");

    //エディタのリスト
	TextureAsset::Register(U"debug_edit_list", U"data/image/debug_test/edit_list.png");
	TextureAsset::Load(U"debug_edit_list");

	TextureAsset::Register(U"debug_edit_enemy", U"data/image/debug_test/enemy.png");
	TextureAsset::Load(U"debug_edit_enemy");

	TextureAsset::Register(U"debug_edit_tile", U"data/image/debug_test/tile.png");
	TextureAsset::Load(U"debug_edit_tile");

	TextureAsset::Register(U"debug_name_button_maru", U"data/image/debug_test/name_button_maru.png");
	TextureAsset::Load(U"debug_name_button_maru");

	TextureAsset::Register(U"debug_name_button_maru_select", U"data/image/debug_test/name_button_maru_select.png");
	TextureAsset::Load(U"debug_name_button_maru_select");

	TextureAsset::Register(U"debug_name_button_batu", U"data/image/debug_test/name_button_batu.png");
	TextureAsset::Load(U"debug_name_button_batu");

	TextureAsset::Register(U"debug_name_button_batu_select", U"data/image/debug_test/name_button_batu_select.png");
	TextureAsset::Load(U"debug_name_button_batu_select");

	TextureAsset::Register(U"debug_name_button_batu_select", U"data/image/debug_test/name_button_batu_select.png");
	TextureAsset::Load(U"debug_name_button_batu_select");

	TextureAsset::Register(U"debug_spanner_mini", U"data/image/debug_test/spanner_mini.png");
	TextureAsset::Load(U"debug_spanner_mini");

	TextureAsset::Register(U"debug_spanner_mini_select", U"data/image/debug_test/spanner_mini_select.png");
	TextureAsset::Load(U"debug_spanner_mini_select");

	//エディタのバック
	TextureAsset::Register(U"debug_edit_back", U"data/image/debug_test/back.png");
	TextureAsset::Load(U"debug_edit_back");

	//エディタのペン
	TextureAsset::Register(U"debug_edit_select", U"data/image/debug_test/edit_select.png");
	TextureAsset::Load(U"debug_edit_select");

	//エディタのペン
	TextureAsset::Register(U"debug_edit_pen", U"data/image/debug_test/pen.png");
	TextureAsset::Load(U"debug_edit_pen");

	//エディタの消しゴム
	TextureAsset::Register(U"debug_edit_eraser", U"data/image/debug_test/eraser.png");
	TextureAsset::Load(U"debug_edit_eraser");

	//エディタのバケツ
	TextureAsset::Register(U"debug_edit_bukket", U"data/image/debug_test/bukket.png");
	TextureAsset::Load(U"debug_edit_bukket");

	//エディタのバケツ消しゴム
	TextureAsset::Register(U"debug_edit_bukket_erase", U"data/image/debug_test/bukket_erase.png");
	TextureAsset::Load(U"debug_edit_bukket_erase");

	//エディタのセーブ
	TextureAsset::Register(U"debug_edit_save", U"data/image/debug_test/save.png");
	TextureAsset::Load(U"debug_edit_save");

	//エディタのダーク
	TextureAsset::Register(U"debug_edit_dark", U"data/image/debug_test/edit_dark.png");
	TextureAsset::Load(U"debug_edit_dark");

	//エディタツールボックスミニ(没)
	TextureAsset::Register(U"debug_edit_enemy_tool", U"data/image/debug_test/edit_enemy_tool.png");
	TextureAsset::Load(U"debug_edit_enemy_tool");

	//エディタの当たり判定の四角形の設置
	TextureAsset::Register(U"debug_edit_plus_hit_rect", U"data/image/debug_test/plus_hit_rect.png");
	TextureAsset::Load(U"debug_edit_plus_hit_rect");

	//エディタの当たり判定の四角形の削除
	TextureAsset::Register(U"debug_edit_back_hit_rect", U"data/image/debug_test/back_hit_rect.png");
	TextureAsset::Load(U"debug_edit_back_hit_rect");
	
	//エディタの弾出し位置
	TextureAsset::Register(U"debug_edit_plus_center", U"data/image/debug_test/plus_center.png");
	TextureAsset::Load(U"debug_edit_plus_center");

	//エディタの情報
	TextureAsset::Register(U"debug_edit_information", U"data/image/debug_test/information.png");
	TextureAsset::Load(U"debug_edit_information");

	//エディタの敵追加
	TextureAsset::Register(U"debug_edit_plus_fish", U"data/image/debug_test/plus_fish.png");
	TextureAsset::Load(U"debug_edit_plus_fish");

	//エディタの敵削除
	TextureAsset::Register(U"debug_edit_minus_fish", U"data/image/debug_test/minus_fish.png");
	TextureAsset::Load(U"debug_edit_minus_fish");

	//エディタの編集
	TextureAsset::Register(U"debug_spanner", U"data/image/debug_test/spanner.png");
	TextureAsset::Load(U"debug_spanner");

	//エディタの編集選択
	TextureAsset::Register(U"debug_spanner_select", U"data/image/debug_test/spanner_select.png");
	TextureAsset::Load(U"debug_spanner_select");

	//敵の登録
	//1体目
	TextureAsset::Register(U"enemy_アンモナイト", U"data/image/fish/enemy/アンモナイト.png");
	TextureAsset::Load(U"enemy_アンモナイト");
	//2体目
	TextureAsset::Register(U"enemy_サケ", U"data/image/fish/enemy/サケ.png");
	TextureAsset::Load(U"enemy_サケ");
	//3体目
	TextureAsset::Register(U"enemy_マグロ", U"data/image/fish/enemy/マグロ.png");
	TextureAsset::Load(U"enemy_マグロ");
	//4体目
	TextureAsset::Register(U"enemy_シーラカンス", U"data/image/fish/enemy/シーラカンス.png");
	TextureAsset::Load(U"enemy_シーラカンス");
	//5体目
	TextureAsset::Register(U"enemy_三葉虫", U"data/image/fish/enemy/三葉虫.png");
	TextureAsset::Load(U"enemy_三葉虫");

}
