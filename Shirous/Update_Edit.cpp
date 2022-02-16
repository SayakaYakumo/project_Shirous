#include"Game.hpp"

void Game::update_edit() {

	switch (edit_scene)
	{
	case 0:
		update_edit_ini();
		edit_scene = 1;
		break;
	case 1:
		update_edit_main();
		break;
	case 2:
		break;
	case 3:
		break;
	default:
		break;
	}

}


void Game::update_edit_ini() {

	edit_display = 1;//ツールボックス表示
	edit_select_item = 1;//ペンに設定

	back_tile.clear();//データ初期化
	emergeEnemys.clear();//データ初期化

	//ステージデータ読み込み
	play_load(debug_stage_number);


}

void Game::update_edit_main() {

	edit_scroll += Mouse::Wheel() * 50 * -1;


	if (MouseR.down()) {//ツールボックスの表示切り替え
		if (edit_display == 0) {
			edit_display = 1;
		}
		else if (edit_display == 1) {
			edit_display = 0;
		}
	}

	if (edit_display == 1) {//エディタリストがでている

		Array<Circle> circle;
		
		for (int i = 0; i < 9; i++) {
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
			
			if(click_number==0) {//メニュー戻る
				edit_scene = 0;
				game_scene = 1;
			}
			else if (click_number == 8) {//セーブ

				//背景タイル保存

				Serializer<BinaryWriter> Bwriter{ U"data/stage/0/BackTile.bin" };

				if (not Bwriter)
				{
					throw Error{ U"Failed to open `tutorial4.bin`" };
				}

				Bwriter(back_tile);


				//敵配置情報保存

				Serializer<BinaryWriter> EEwriter{ U"data/stage/0/emerge_enemy.bin" };

				if (not EEwriter)
				{
					throw Error{ U"Failed to open `tutorial4.bin`" };
				}

				EEwriter(emergeEnemys);


				edit_saved_display_fade = 1;
			}
			else {//ツール変更
				edit_select_item = click_number;
			}
		}

	}




	if (edit_display == 0) {//アイテム選択中ではない

		if (edit_select_item == 1) {//ペン

			if (MouseL.pressed()) {
				int x = (Cursor::Pos().x + edit_scroll) / 120;
				int y = Cursor::Pos().y / 120;

				for (size_t i = 0; i < back_tile.size(); i++) {
					if (back_tile[i].get_x() == x && back_tile[i].get_y() == y) {
						back_tile[i].set_kind(edit_select_tile_kind);
					}
				}
			}

		}
		else if (edit_select_item == 2) {//消しゴム
			if (MouseL.pressed()) {
				int x = (Cursor::Pos().x + edit_scroll) / 120;
				int y = Cursor::Pos().y / 120;

				for (size_t i = 0; i < back_tile.size(); i++) {
					if (back_tile[i].get_x() == x && back_tile[i].get_y() == y) {
						back_tile[i].set_kind(-1);
					}
				}
			}
		}
		else if (edit_select_item == 3) {//バケツ
			if (MouseL.down()) {
				if (edit_bukket == 0) {
					edit_bukket_start_x = (Cursor::Pos().x + edit_scroll) / 120;
					edit_bukket_start_y = Cursor::Pos().y / 120;
					edit_bukket = 1;
				}
			}
		}
		else if (edit_select_item == 4) {//消すバケツ
			if (MouseL.down()) {
				if (edit_bukket == 0) {
					edit_bukket_start_x = (Cursor::Pos().x + edit_scroll) / 120;
					edit_bukket_start_y = Cursor::Pos().y / 120;
					edit_bukket = 1;
				}
			}
		}
		else if (edit_select_item == 5) {//敵追加

			if (MouseL.down()) {
				edit_plus_enemy_name = U"アンモナイト";
				String name = edit_plus_enemy_name;
				int x = Cursor::Pos().x + edit_scroll;
				int y = Cursor::Pos().y;
				double time = 2;
				emergeEnemys.push_back(EmergeEnemy(name, x, y, time));
			}
		}
		else if (edit_select_item == 6) {//敵削除

			if (MouseL.down()) {
				int x = Cursor::Pos().x + edit_scroll;
				int y = Cursor::Pos().y;
				Rect rect = Rect(x, y, 1, 1);

				Array<Rect>rects;

				for (size_t i = 0; i < emergeEnemys.size(); i++) {
					String name = emergeEnemys[i].get_name();

					int x = emergeEnemys[i].get_x();
					int y = emergeEnemys[i].get_y();

					for (size_t e = 0; e < enemy_data.size(); e++) {
						if (name == emergeEnemys[i].get_name()) {

							rects = enemy_data[e].get_rects();//当たり判定の四角形

							for (size_t r = 0; r < rects.size(); r++) {

								Rect rected = rects[r].movedBy(x, y);

								if (rect.intersects(rected)) {
									emergeEnemys[i].set_edit_mark(1);
								}
							}
						}
					}

				}

				emergeEnemys.remove_if([&](EmergeEnemy e) {
					if (e.get_edit_mark() == 1) {

						return true;
					}
					else {
						return false;
					}

			});


				for (size_t i = 0; i < emergeEnemys.size(); i++) {
					emergeEnemys[i].set_edit_mark(0);
				}

			}
		}



		if (edit_select_item == 3 || edit_select_item == 4) {//バケツ

			if (edit_bukket == 1) {//バケツ中

				for (size_t i = 0; i < back_tile.size(); i++) {
					back_tile[i].set_edit_kind_x(-1);
					back_tile[i].set_edit_kind_y(-1);
				}


				int end_x = (Cursor::Pos().x + edit_scroll) / 120;
				int end_y = Cursor::Pos().y / 120;

				int start_x = edit_bukket_start_x;
				int start_y = edit_bukket_start_y;

				if (start_x == end_x) {
					for (size_t i = 0; i < back_tile.size(); i++) {
						if (back_tile[i].get_x() == start_x) {
							back_tile[i].set_edit_kind_x(1);
						}
					}
				}


				if (start_x < end_x) {//終わりの方が右側

					for (size_t i = 0; i < back_tile.size(); i++) {
						if (start_x <= back_tile[i].get_x() && back_tile[i].get_x() <= end_x) {
							back_tile[i].set_edit_kind_x(1);
						}

					}

				}

				if (end_x < start_x) {

					for (size_t i = 0; i < back_tile.size(); i++) {
						if (end_x <= back_tile[i].get_x() && back_tile[i].get_x() <= start_x) {
							back_tile[i].set_edit_kind_x(1);
						}

					}
				}

				if (start_y == end_y) {
					for (size_t i = 0; i < back_tile.size(); i++) {
						if (back_tile[i].get_y() == start_y) {
							back_tile[i].set_edit_kind_y(1);
						}
					}
				}

				if (start_y < end_y) {//終わりの方が右側

					for (size_t i = 0; i < back_tile.size(); i++) {
						if (start_y <= back_tile[i].get_y() && back_tile[i].get_y() <= end_y) {
							back_tile[i].set_edit_kind_y(1);
						}

					}

				}

				if (end_y < start_y) {

					for (size_t i = 0; i < back_tile.size(); i++) {
						if (end_y <= back_tile[i].get_y() && back_tile[i].get_y() <= start_y) {
							back_tile[i].set_edit_kind_y(1);
						}

					}
				}



				//バケツ終わり
				if (MouseL.up()) {

					if (edit_select_item == 3) {//塗るバケツ

						//マークがついているタイルを塗り替える
						for (size_t i = 0; i < back_tile.size(); i++) {
							if (back_tile[i].get_edit_kind_x() != -1 && back_tile[i].get_edit_kind_y() != -1) {
								back_tile[i].set_kind(0);
							}
						}

					}
					else if (edit_select_item == 4) {//消すバケツ

							//マークがついているタイルを消す
						for (size_t i = 0; i < back_tile.size(); i++) {
							if (back_tile[i].get_edit_kind_x() != -1 && back_tile[i].get_edit_kind_y() != -1) {
								back_tile[i].set_kind(-1);
							}
						}
					}

					//エディタマークを消す
					for (size_t i = 0; i < back_tile.size(); i++) {
						if (back_tile[i].get_edit_kind_x() != -1 && back_tile[i].get_edit_kind_y() != -1) {
							back_tile[i].reset_edit_kind();
						}
					}

					edit_bukket = 0;
				}
			}
		}

	}

	




}
