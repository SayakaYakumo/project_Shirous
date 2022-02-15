#include"Game.hpp"

void Game::draw_debug_menu() {

	TextureAsset(U"menu_back").draw(0, 0);

	switch (debug_menu_scene)
	{
	case 0:
		draw_debug_menu_stage_select();
		break;
	case 1:
		draw_debug_menu_mode_select();
		break;
	case 2://プレイヤー編集
		draw_edit_player();
		break;
	case 3://オプション編集
		draw_edit_option();
		break;
	case 4://敵編集
		draw_edit_enemy();
		break;
	default:
		break;
	}


}


void Game::draw_debug_menu_stage_select() {

	for (int x = 0; x < 5; x++) {
		for (int y = 0; y < 3; y++) {
			TextureAsset(U"debug_menu_rect_frame").draw(195 + x * (250 + 70), 150 + y * (250 + 50));

			if (debug_cur_cover_x == x && debug_cur_cover_y == y) {
				TextureAsset(U"debug_menu_rect_select_frame").draw(195 + x * (250 + 70), 150 + y * (250 + 50));
			}

			if (y == 0 || y == 1) {

				String number = Format(y * 5 + x);

				FontAsset(U"DebugMenuFont")(U"Stage").draw(195 + x * (250 + 70) + 67, 150 + y * (250 + 50) + 10);
				FontAsset(U"DebugMenuFont2")(number).draw(195 + x * (250 + 70) + 90, 150 + y * (250 + 50) + 70);

			}

			if (y == 2) {
				switch (x)
				{
				case 0:
					FontAsset(U"DebugMenuFont4")(U"Player").drawAt(195 + x * (250 + 70) + 125, 150 + y * (250 + 50) + 110);
					break;
				case 1:
					FontAsset(U"DebugMenuFont4")(U"Option").drawAt(195 + x * (250 + 70) + 125, 150 + y * (250 + 50) + 110);
					break;
				case 2:
					FontAsset(U"DebugMenuFont4")(U"Enemy").drawAt(195 + x * (250 + 70) + 125, 150 + y * (250 + 50) + 110);
					break;
				case 3:
					//FontAsset(U"DebugMenuFont4")(U"").drawAt(195 + x * (250 + 70) + 125, 150 + y * (250 + 50) + 110);
					break;
				case 4:
					break;
				default:
					break;
				}
			}

		}
	}

	

	


}

void Game::draw_debug_menu_mode_select() {

	FontAsset(U"DebugMenuFont3")(U"Stage "+Format(debug_stage_number)).drawAt(1920 / 2, 200);


	for (int x = 0; x < 3; x++) {
		

		TextureAsset(U"debug_menu_rect_frame").draw(515 + x * (250 + 70),600);

		if (debug_2_cur_cover == x) {
			TextureAsset(U"debug_menu_rect_select_frame").draw(515 + x * (250 + 70), 600);
		}

		switch (x)
		{
		case 0:
			FontAsset(U"DebugMenuFont4")(U"Back").draw(515 + x * (250 + 70) + 55, 600+80);
			break;
		case 1:
			FontAsset(U"DebugMenuFont4")(U"Play").draw(515 + x * (250 + 70) + 55, 600+80);
			break;
		case 2:
			FontAsset(U"DebugMenuFont4")(U"Edit").draw(515 + x * (250 + 70) + 55, 600+80);
			break;
		default:
			break;
		}
	}


}


void Game::draw_edit_player() {

}

void Game::draw_edit_option() {

}

void Game::draw_edit_enemy() {

	if (edit_enemy_scene == 0) {//enemy一覧を表示

		for (int x = 0; x < 5; x++) {
			for (int y = 0; y < 3; y++) {
				TextureAsset(U"debug_menu_rect_frame").draw(195 + x * (250 + 70), 150 + y * (250 + 50));
			}
		}


		int page_y_begin = edit_enemy_page * 3;
		int page_y_end = (edit_enemy_page * 3) + 2;

		for (size_t i = 0; i < enemy_data.size(); i++) {

			int v = enemy_data[i].get_y();

			if (page_y_begin <= v && v <= page_y_end) {//ページ内なので描画

				int x_pos = enemy_data[i].get_x();
				int y_pos = enemy_data[i].get_y() - edit_enemy_page * 3;

				String name = enemy_data[i].get_name();

				//Print << U"i::" << i;
				//Print << U"x::" << enemy_data[i].get_x();
				//Print << U"y::" << enemy_data[i].get_y();
				//Print << U"=======";

				int y_v = 200;

				FontAsset(U"DebugMenuFont5")(name).drawAt(195 + x_pos * (250 + 70) + 120, 150 + y_pos * (250 + 50) + 150);

				//FontAsset(U"DebugMenuFont5")(i).draw(195 + x_pos * (250 + 70)+50, 150 + y_pos * (250 + 50)+100);
			}

		}

		if (KeyZ.down()) {

			enemy_data[0].set_name(U"アンモナイト");

			//Print << U"save";
			// バイナリファイルをオープン
			Serializer<BinaryWriter> writer{ U"data/database/fish_data.bin" };

			if (not writer) // もしオープンに失敗したら
			{
				throw Error{ U"Failed to open `tutorial4.bin`" };
			}

			// シリアライズに対応したデータを記録
			writer(enemy_data);
		}

	}
	else if (edit_enemy_scene == 1) {//エディタ画面

		String name = enemy_data[edit_enemy_index].get_name();//名前を取得

		FontAsset(U"DebugMenuFont6")(name).draw(50,20);//名前を記述

		String texture_name = U"enemy_" + name;

		//表示用のずらし分
		int x_display = 100;
		int y_display = 200;

		TextureAsset(texture_name).draw(x_display, y_display);//画像を描画

		int rect_count = 0;//色変える用

		for (size_t i = 0; i < enemy_data[edit_enemy_index].get_rect_size(); i++) {//当たり判定の四角を描画
			Rect rect = enemy_data[edit_enemy_index].get_rect(i).movedBy(x_display, y_display);
			rect.drawFrame(2, 2, HSV(rect_count * 30, 1.0, 1.0, 0.9));
			rect_count++;
		}

		if (edit_enemy_make_rect_scene == 1) {//表示用の四角
			Rect rect = edit_enemy_rect.movedBy(x_display, y_display);
			rect.drawFrame(2, 2, Palette::White);
		}

		TextureAsset(U"debug_edit_dark").draw(1050, 150, ColorF(1.0, 0.5));//黒い幕を表示

		int size = enemy_data[edit_enemy_index].get_rect_size();

		FontAsset(U"DebugMenuFont")(U"当たり判定の数　"+Format(size)).draw(1920 - 800, 45);

		//ステータス表示

		int hp = enemy_data[edit_enemy_index].get_hp();

		FontAsset(U"DebugMenuFont6")(U"HP").draw(1100, 200);
		FontAsset(U"DebugMenuFont6")(Format(hp)).draw(1100+400, 200);

		int act = enemy_data[edit_enemy_index].get_act();

		FontAsset(U"DebugMenuFont6")(U"Act").draw(1100, 300);
		FontAsset(U"DebugMenuFont6")(Format(act)).draw(1100+400, 300);

		int move = enemy_data[edit_enemy_index].get_move();

		FontAsset(U"DebugMenuFont6")(U"Move").draw(1100, 400);
		FontAsset(U"DebugMenuFont6")(Format(move)).draw(1100+400, 400);

		int shot = enemy_data[edit_enemy_index].get_shot();

		FontAsset(U"DebugMenuFont6")(U"Shot").draw(1100, 500);
		FontAsset(U"DebugMenuFont6")(Format(shot)).draw(1100+400, 500);

		if (edit_enemy_display == 1) {//ツールボックスを表示

			//ツールボックス
			TextureAsset(U"debug_edit_list").draw(60, 1080 - 150 - 10);
			TextureAsset(U"debug_edit_back").draw(10 + 60 + (120 + 50) * 0, 1080 - 150 + 15 - 10);
			TextureAsset(U"debug_edit_plus_hit_rect").draw(10 + 60 + (120 + 50) * 1, 1080 - 150 + 15 - 10);
			TextureAsset(U"debug_edit_back_hit_rect").draw(10 + 60 + (120 + 50) * 2, 1080 - 150 + 15 - 10);
			TextureAsset(U"debug_edit_plus_center").draw(10 + 60 + (120 + 50) * 3, 1080 - 150 + 15 - 10);
			TextureAsset(U"debug_edit_information").draw(10 + 60 + (120 + 50) * 4, 1080 - 150 + 15 - 10);
			TextureAsset(U"debug_edit_save").draw(10 + 60 + (120 + 50) * 5, 1080 - 150 + 15 - 10);

			if (edit_enemy_select_item != 0) {//backではない
				TextureAsset(U"debug_edit_select").draw(10 + 60 + (120 + 50) * edit_enemy_select_item, 1080 - 150 + 15 - 10);
			}

		}

		if (edit_enemy_saved_display_fade > 0) {//save表示
			FontAsset(U"DebugMenuFont2")(U"セーブしました").drawAt(1920 / 2, 1080 / 2, ColorF(1.0, edit_enemy_saved_display_fade));
			edit_enemy_saved_display_fade -= 0.0111;
		}
	}

}
