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

		TextureAsset(U"debug_menu_rect_frame_mini").draw(30,1080-180-30);
		FontAsset(U"DebugMenuFont7")(U"Back").draw(30+30, 1080-180 - 30+50);
		
		TextureAsset(U"debug_menu_rect_frame_mini").draw(30+200+50, 1080 - 180 - 30);
		FontAsset(U"DebugMenuFont8")(U"＋").draw(30 + 30+200+50, 1080 - 180 - 30 + 0);

		TextureAsset(U"debug_menu_rect_frame_mini").draw(30+400+100, 1080 - 180 - 30);
		FontAsset(U"DebugMenuFont8")(U"－").draw(30 + 30+400+100, 1080 - 180 - 30 + 0);

		if (edit_enemy_cur_cover != -1) {
			int x = edit_enemy_cur_cover;
			TextureAsset(U"debug_menu_rect_frame_mini_select").draw(30+(250*x), 1080 - 180 - 30);
		}
		

		FontAsset(U"DebugMenuFont6")(U"Page　" + Format(edit_enemy_page)).draw(1250, 900);

		TextureAsset(U"debug_menu_rect_frame_mini_2").draw(1000,900);
		FontAsset(U"DebugMenuFont6")(U"－").draw(1000+25 , 900+10);

		TextureAsset(U"debug_menu_rect_frame_mini_2").draw(1000+750-120, 900);
		FontAsset(U"DebugMenuFont6")(U"＋").draw(1000 + 750 - 120+25, 900+10 );

		if (edit_enemy_cur_cover_2 != -1) {
			if (edit_enemy_cur_cover_2 == 0) {
				TextureAsset(U"debug_menu_rect_frame_mini_2_select").draw(1000, 900);
			}
			else if (edit_enemy_cur_cover_2 == 1) {
				TextureAsset(U"debug_menu_rect_frame_mini_2_select").draw(1000 + 750 - 120, 900);
			}
		}

		for (int i = 0; i < 7; i++) {
			TextureAsset(U"debug_menu_rect_frame_enemy").draw(1000, 30 + i * (100 + 20));
		}

		if (edit_enemy_cur_cover_3 != -1) {
			int y = edit_enemy_cur_cover_3;
			TextureAsset(U"debug_menu_rect_select_frame_enemy").draw(1000, 30 +  y* (100 + 20));

			String name = U"no_data";

			int page = edit_enemy_page;
			int page_begin = page * 7;
			int number = page_begin+ edit_enemy_cur_cover_3;

			if (number <= enemy_data.size() - 1) {
				name = enemy_data[number].get_name();
				
			}

			if (name != U"no_data") {
				String texture_name = U"enemy_" + name;

				TextureAsset(texture_name).draw(100, 200);

				//Print << U"t_name::" << texture_name;

				TextureAsset(U"enemy_サケ").draw(100, 200);

			}
		
		}



		int page = edit_enemy_page;
		int page_begin = page * 7;
		int page_end = page * 7 + 6;

		for (size_t i = 0; i < enemy_data.size(); i++) {

			if (page_begin <= i && i <= page_end) {
				String name = enemy_data[i].get_name();
				int y = i - page_begin;
				FontAsset(U"DebugMenuFont6")(name).draw(1000+20, 30 + y * (100 + 20));
				String name2 = enemy_data[i].get_name2();
				int v=name.size();
				FontAsset(U"DebugMenuFont")(name2).draw(1000 +20+(70)*(v+1)-50, 30 + y * (100 + 20)+30);
			}

		}




	}
	else if (edit_enemy_scene ==1 || edit_enemy_scene == 2) {//エディタ画面

		String name = enemy_data[edit_enemy_index].get_name();//名前を取得

		FontAsset(U"DebugMenuFont6")(name).draw(50,20);//名前を記述

		String name2 = enemy_data[edit_enemy_index].get_name2();//名前を取得

		FontAsset(U"DebugMenuFont")(name2).draw(70, 120);//名前を記述

		String texture_name = U"enemy_" + name;

		//表示用のずらし分
		int x_display = 100;
		int y_display = 200;

		if (name != U"no_data") {
			TextureAsset(texture_name).draw(x_display, y_display);//画像を描画
		}
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

		if (edit_enemy_display == 1 || edit_enemy_display == 2) {//ツールボックス表示中
			if (edit_enemy_information == 1) {//インフォメーション表示中

				TextureAsset(U"debug_edit_dark").draw(1050, 150, ColorF(1.0, 0.5));//黒い幕を表示

				int size = enemy_data[edit_enemy_index].get_rect_size();

				FontAsset(U"DebugMenuFont")(U"当たり判定の数　" + Format(size)).draw(1920 - 800, 45);

				//ステータス表示

				TextureAsset(U"debug_spanner").draw(800,30);//名前変更

				

				if (edit_enemy_information_cover==100) {
					TextureAsset(U"debug_spanner_select").draw(800, 30);
				}

				
				TextureAsset(U"debug_spanner_mini").draw(700, 100);//名前2変更

				if (edit_enemy_information_cover == 1000) {
					TextureAsset(U"debug_spanner_mini_select").draw(700, 100);
				}

				



				for (int i = 0; i < 4; i++) {
					TextureAsset(U"debug_spanner").draw(1100 + 500, 210 + i * (120));
				}

				if (edit_enemy_information_cover != -1&& edit_enemy_information_cover != 100) {
					TextureAsset(U"debug_spanner_select").draw(1100 + 500, 210 + edit_enemy_information_cover * (120));
				}



				for (int y = 0; y < 5; y++) {//敵情報

					int y_v = 200;
					int y_v2 = 120;

					if (y == 0) {

						int hp = enemy_data[edit_enemy_index].get_hp();
						FontAsset(U"DebugMenuFont6")(U"HP").draw(1100, y_v);
						FontAsset(U"DebugMenuFont6")(Format(hp)).draw(1100 + 300, y_v);
					}
					else if (y == 1) {

						int act = enemy_data[edit_enemy_index].get_act();
						if (act != -1) {
							FontAsset(U"DebugMenuFont6")(U"Act").draw(1100, y_v + y_v2 * y);
							FontAsset(U"DebugMenuFont6")(Format(act)).draw(1100 + 300, y_v + y_v2 * y);
						}
						else if (act == -1) {
							FontAsset(U"DebugMenuFont6")(U"Act").draw(1100, y_v + y_v2 * y, ColorF(1.0, 0.5));
							FontAsset(U"DebugMenuFont6")(Format(act)).draw(1100 + 300, y_v + y_v2 * y, ColorF(1.0, 0.5));
						}
					}
					else if (y == 2) {

						int move = enemy_data[edit_enemy_index].get_move();

						int act = enemy_data[edit_enemy_index].get_act();
						if (act == -1) {
							FontAsset(U"DebugMenuFont6")(U"Move").draw(1100, y_v + y_v2 * y);
							FontAsset(U"DebugMenuFont6")(Format(move)).draw(1100 + 300, y_v + y_v2 * y);
						}
						else if (act != -1) {
							FontAsset(U"DebugMenuFont6")(U"Move").draw(1100, y_v + y_v2 * y, ColorF(1.0, 0.5));
							FontAsset(U"DebugMenuFont6")(Format(move)).draw(1100 + 300, y_v + y_v2 * y, ColorF(1.0, 0.5));
						}
					}
					else if (y == 3) {

						int shot = enemy_data[edit_enemy_index].get_shot();

						int act = enemy_data[edit_enemy_index].get_act();
						if (act == -1) {
							FontAsset(U"DebugMenuFont6")(U"Shot").draw(1100, y_v + y_v2 * y);
							FontAsset(U"DebugMenuFont6")(Format(shot)).draw(1100 + 300, y_v + y_v2 * y);
						}
						else if (act != -1) {
							FontAsset(U"DebugMenuFont6")(U"Shot").draw(1100, y_v + y_v2 * y, ColorF(1.0, 0.5));
							FontAsset(U"DebugMenuFont6")(Format(shot)).draw(1100 + 300, y_v + y_v2 * y, ColorF(1.0, 0.5));
						}
					}

				}


			}

		}

		if (edit_enemy_display == 1) {//ツールボックスを表示

			//ツールボックス
			TextureAsset(U"debug_edit_list").draw(60, 1080 - 150 - 10);
			TextureAsset(U"debug_edit_back").draw(10 + 60 + (120 + 50) * 0, 1080 - 150 + 15 - 10);
			TextureAsset(U"debug_edit_plus_hit_rect").draw(10 + 60 + (120 + 50) * 1, 1080 - 150 + 15 - 10);
			TextureAsset(U"debug_edit_back_hit_rect").draw(10 + 60 + (120 + 50) * 2, 1080 - 150 + 15 - 10);
			TextureAsset(U"debug_edit_plus_center").draw(10 + 60 + (120 + 50) * 3, 1080 - 150 + 15 - 10);
			TextureAsset(U"debug_edit_information").draw(10 + 60 + (120 + 50) * 4, 1080 - 150 + 15 - 10);
			TextureAsset(U"debug_edit_save").draw(10 + 60 + (120 + 50) * 5, 1080 - 150 + 15 - 10);

			if (edit_enemy_select_item != 0&& edit_enemy_select_item != 4) {//backではない
				TextureAsset(U"debug_edit_select").draw(10 + 60 + (120 + 50) * edit_enemy_select_item, 1080 - 150 + 15 - 10);
			}

			if (edit_enemy_information == 1) {
				TextureAsset(U"debug_edit_select").draw(10 + 60 + (120 + 50) * 4, 1080 - 150 + 15 - 10);
			}

		}

		if (edit_enemy_saved_display_fade > 0) {//save表示
			FontAsset(U"DebugMenuFont2")(U"セーブしました").drawAt(1920 / 2, 1080 / 2, ColorF(1.0, edit_enemy_saved_display_fade));
			edit_enemy_saved_display_fade -= 0.0111;
		}


		if (edit_enemy_display == 2) {//数値入力画面
			if (edit_enemy_information_scene!=100&& edit_enemy_information_scene != 1000) {//数値入力
				draw_edit_input_number();
			}
			else if (edit_enemy_information_scene == 100) {//文字入力
				TextureAsset(U"change_scene_fade").draw(0,0,ColorF(1.0,0.8));
				FontAsset(U"DebugMenuFont")(U"キーボードで入力").drawAt(1920 / 2, (1080-600) / 2);
				FontAsset(U"DebugMenuFont")(U"（「CAPS LOCK」に注意）").drawAt(1920 / 2, (1080 - 400) / 2);

				String name = enemy_data[edit_enemy_index].get_name();//名前を取得
				FontAsset(U"DebugMenuFont")(name).drawAt(1920 / 2, (1080) / 2);

				FontAsset(U"DebugMenuFont")(U"↓").drawAt(1920 / 2, (1080+200) / 2);
				
				FontAsset(U"DebugMenuFont")(edit_enemy_name+edit_enemy_name_editing).drawAt(1920 / 2, (1080 + 400) / 2);//新しい名前

				TextureAsset(U"debug_name_button_maru").draw(10, 1080 - 10 - 180);

				if (edit_enemy_name_cover==0) {
					TextureAsset(U"debug_name_button_maru_select").draw(10, 1080 - 10 - 180);
				}

				TextureAsset(U"debug_name_button_batu").draw(10 + 180 + 30, 1080 - 10 - 180);

				if (edit_enemy_name_cover==1) {
					TextureAsset(U"debug_name_button_batu_select").draw(10 + 180 + 30, 1080 - 10 - 180);
				}


			}
			else if (edit_enemy_information_scene==1000) {
				TextureAsset(U"change_scene_fade").draw(0, 0, ColorF(1.0, 0.8));
				FontAsset(U"DebugMenuFont")(U"キーボードで入力").drawAt(1920 / 2, (1080 - 600) / 2);
				FontAsset(U"DebugMenuFont")(U"（「CAPS LOCK」に注意）").drawAt(1920 / 2, (1080 - 400) / 2);

				String name = enemy_data[edit_enemy_index].get_name2();//名前を取得
				FontAsset(U"DebugMenuFont")(name).drawAt(1920 / 2, (1080) / 2);

				FontAsset(U"DebugMenuFont")(U"↓").drawAt(1920 / 2, (1080 + 200) / 2);

				FontAsset(U"DebugMenuFont")(edit_enemy_name_2 + edit_enemy_name_editing_2).drawAt(1920 / 2, (1080 + 400) / 2);//新しい名前

				TextureAsset(U"debug_name_button_maru").draw(10, 1080 - 10 - 180);

				if (edit_enemy_name_cover == 0) {
					TextureAsset(U"debug_name_button_maru_select").draw(10, 1080 - 10 - 180);
				}

				TextureAsset(U"debug_name_button_batu").draw(10 + 180 + 30, 1080 - 10 - 180);

				if (edit_enemy_name_cover == 1) {
					TextureAsset(U"debug_name_button_batu_select").draw(10 + 180 + 30, 1080 - 10 - 180);
				}
			}
		}

	}

}
