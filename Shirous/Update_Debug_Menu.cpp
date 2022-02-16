#include"Game.hpp"

void Game::update_debug_menu() {

	switch (debug_menu_scene)
	{
	case 0:
		update_debug_menu_stage_select();
		break;
	case 1:
		update_debug_menu_mode_select();
		break;
	case 2://プレイヤー編集
		update_edit_player();
		break;
	case 3://オプション編集
		update_edit_option();
		break;
	case 4://敵編集
		update_edit_enemy();
		break;
	default:
		break;
	}
	
}

void Game::update_debug_menu_stage_select() {

	class Select_Box {
	public:
		Select_Box(int x_,int y_,Rect rect_) {
			x = x_;
			y = y_;
			rect = rect_;
		}
		Rect rect;
		int x, y;
	};

	Array<Select_Box> select_box;



	for (int x = 0; x < 5; x++) {
		for (int y = 0; y < 3; y++) {
			select_box.push_back(Select_Box(x, y,Rect(195 + x * (250 + 70), 150 + y * (250 + 50), 250, 250)));
		}
	}

	int select_box_number_x = -1;
	int select_box_number_y = -1;

	Cursor::RequestStyle(CursorStyle::Default);

	for (size_t i = 0; i < select_box.size(); i++) {
		if (select_box[i].rect.mouseOver()) {
			Cursor::RequestStyle(CursorStyle::Hand);
			select_box_number_x = select_box[i].x;
			select_box_number_y = select_box[i].y;
		}

	}


	

	//描画用
	debug_cur_cover_x = -1;
	debug_cur_cover_y = -1;

	debug_cur_cover_x = select_box_number_x;
	debug_cur_cover_y = select_box_number_y;
	


	if (MouseL.down()) {

		if (select_box_number_y == 0 || select_box_number_y == 1) {//デバッグステージメニューへ

			debug_stage_number = select_box_number_y * 5 + select_box_number_x;


			debug_menu_scene = 1;

			
		}
		else if (select_box_number_y == 2) {//エディタへ

			switch (select_box_number_x)
			{
			case 0://プレイヤー編集へ
				break;
			case 1://オプション編集へ
				break;
			case 2://エネミー編集へ
				debug_menu_scene = 4;
				break;
			case 3:
				break;
			default:
				break;
			}

		}

	
	}

}

void Game::update_debug_menu_mode_select() {

	Array<Rect> rect;

	for (int i = 0; i < 3; i++) {
		rect.push_back(Rect(515 + i * (250 + 70), 600, 250, 250));
	}

	int click_number = -1;

	Cursor::RequestStyle(CursorStyle::Default);

	for (size_t i = 0; i < rect.size(); i++) {
		if (rect[i].mouseOver()) {
			Cursor::RequestStyle(CursorStyle::Hand);
			click_number = i;
		}

	}


	debug_2_cur_cover = -1;

	debug_2_cur_cover = click_number;


	if (MouseL.down()) {
		
		switch (click_number)
		{
		case 0://戻る
			debug_menu_scene = 0;
			break;
		case 1://プレイ
			stage_number = debug_stage_number;
			change_scene(2);
			break;
		case 2://エディタ
			game_scene = 3;
			break;
		default:
			break;
		}

	}
}

void Game::update_edit_player() {

}

void Game::update_edit_option() {

}

void Game::update_edit_enemy() {

	if (edit_enemy_scene == 0) {//敵を選択

		if (KeyZ.down()) {//エディタのデバッグ用
			edit_enemy_scene = 1;
		}


		Array<Rect>rect;

		for (int i = 0; i < 3; i++) {
			rect.push_back(Rect(30+(250*i), 1080 - 180 - 30,180,180));
		}


		Cursor::RequestStyle(CursorStyle::Default);

		int click_number = -1;
		edit_enemy_cur_cover = -1;

		for (size_t i = 0; i < rect.size(); i++) {
			if (rect[i].mouseOver()) {
				click_number = i;
				Cursor::RequestStyle(CursorStyle::Hand);
				edit_enemy_cur_cover = i;
			}
		}


		if (MouseL.down()) {

			switch (click_number)
			{
			case 0://デバッグメニューへ
				debug_menu_scene = 0;
				break;
			case 1:
				break;
			case 2:
				break;
			default:
				break;
			}
		}



		Array<Rect>rect_2;

		
		rect_2.push_back(Rect(1000, 900,120,120));
		rect_2.push_back(Rect(1000 + 750 - 120, 900,120,120));


		Cursor::RequestStyle(CursorStyle::Default);

		int click_number_2 = -1;
		edit_enemy_cur_cover_2 = -1;

		for (size_t i = 0; i < rect_2.size(); i++) {
			if (rect_2[i].mouseOver()) {
				click_number_2 = i;
				Cursor::RequestStyle(CursorStyle::Hand);
				edit_enemy_cur_cover_2 = i;
			}
		}


		if (MouseL.down()) {
			if (click_number_2 == 0) {//ページ減少
				edit_enemy_page--;
			}
			else if (click_number_2 == 1) {//ページ増加
				edit_enemy_page++;
			}
		}


		if (edit_enemy_page==-1) {
			edit_enemy_page = 0;
		}

		if (edit_enemy_page == 4) {
			edit_enemy_page = 3;
		}

	}
	else if (edit_enemy_scene == 1) {//エディタ画面

		if (MouseR.down()) {
			if (edit_enemy_display == 0) {
				edit_enemy_display = 1;
			}
			else if (edit_enemy_display == 1) {
				edit_enemy_display = 0;
			}
		}

		
		

		if (edit_enemy_display == 0) {//ツールボックス非表示中

			if (edit_enemy_select_item == 1) {//hit_rectの追加
			
				if (edit_enemy_make_rect_scene == 0) {//始点設定
				
					if (MouseL.down()) {

						//表示との差分調整
						int ad_x = 100;
						int ad_y = 200;

						edit_enemy_make_rect_x = Cursor::Pos().x - ad_x;
						edit_enemy_make_rect_y = Cursor::Pos().y - ad_y;

						edit_enemy_make_rect_scene = 1;
					}
				}

				if (edit_enemy_make_rect_scene == 1) {//選択中

					if (MouseL.pressed()) {

						//表示との差分調整
						int ad_x = 100;
						int ad_y = 200;

						int old_x = edit_enemy_make_rect_x;
						int old_y = edit_enemy_make_rect_y;
						int now_x = Cursor::Pos().x-ad_x;
						int now_y = Cursor::Pos().y-ad_y;

						//分かりやすさ重視でこのコードを使います
						//おそらくabsなどで省略可

						


						if (old_x < now_x) {
							if (old_y < now_y) {
								edit_enemy_rect.x = old_x;
								edit_enemy_rect.y = old_y;
								edit_enemy_rect.w = now_x - old_x;
								edit_enemy_rect.h = now_y - old_y;
							}
						}

						if (old_x < now_x) {
							if (old_y > now_y) {
								edit_enemy_rect.x = old_x;
								edit_enemy_rect.y = now_y;
								edit_enemy_rect.w = now_x - old_x;
								edit_enemy_rect.h = old_y - now_y;
							}
						}


						if (old_x > now_x) {
							if (old_y < now_y) {
								edit_enemy_rect.x = now_x;
								edit_enemy_rect.y = old_y;
								edit_enemy_rect.w = old_x - now_x;
								edit_enemy_rect.h = now_y - old_y;
							}
						}

						if (old_x > now_x) {
							if (old_y > now_y) {
								edit_enemy_rect.x = now_x;
								edit_enemy_rect.y = now_y;
								edit_enemy_rect.w = old_x - now_x;
								edit_enemy_rect.h = old_y - now_y;
							}
						}

                        
						


					}


					if (MouseL.up()) {//Rect 追加
						if (edit_enemy_rect.w != 0 && edit_enemy_rect.h != 0) {
							enemy_data[edit_enemy_index].plus_rect(edit_enemy_rect);
						}
						edit_enemy_make_rect_scene = 0;
						edit_enemy_rect = Rect(-2000, -2000, 0, 0);//見えなくする
					}

				}


			}
			else if(edit_enemy_select_item==2){//hit_rectを削除(改善の余地あり)
				if (MouseL.down()) {
					enemy_data[edit_enemy_index].back_rect();
				}
			}
			else if (edit_enemy_select_item == 3) {//弾発生点を置く
				if (MouseL.down()) {

				}
			}




		}
		else if (edit_enemy_display == 1) {//ツールボックス表示中

			Array<Circle> circle;

			for (int i = 0; i < 6; i++) {
				circle.push_back(Circle(60 + 10 + 60 + (120 + 50) * i, 1080 - 150 + 15 - 10 + 60, 60));
			}

			cir = circle[0];//デバッグ用

			int click_number = -1;

			Cursor::RequestStyle(CursorStyle::Default);

			for (size_t i = 0; i < circle.size(); i++) {
				if (circle[i].mouseOver()) {
					Cursor::RequestStyle(CursorStyle::Hand);
				}

			}


			for (size_t i = 0; i < circle.size(); i++) {
				if (circle[i].leftClicked()) {
					click_number = i;
				}

			}

			if (click_number != -1) {//押された

				if (click_number == 0) {//メニュー戻る
					
					edit_enemy_scene = 0;
					edit_enemy_select_item = 1;
				}
				else if (click_number == 5) {//セーブ

					// バイナリファイルをオープン
					Serializer<BinaryWriter> writer{ U"data/database/enemy_data.bin" };

					if (not writer) // もしオープンに失敗したら
					{
						throw Error{ U"Failed to open `tutorial4.bin`" };
					}

					// シリアライズに対応したデータを記録
					writer(enemy_data);

					edit_enemy_saved_display_fade = 1;
				}
				else {//ツール変更
					edit_enemy_select_item = click_number;
				}
			}




		}
	}

}


