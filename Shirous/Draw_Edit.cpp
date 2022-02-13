#include"Game.hpp"

void Game::draw_edit() {

	//仮おき背景
	switch (stage_number)
	{
	case 0:
		TextureAsset(U"stage_0_back").draw(0, 0);
		break;
	case 1:
		TextureAsset(U"stage_1_back").draw(0, 0);
		break;
	case 2:
		TextureAsset(U"stage_2_back").draw(0, 0);
		break;
	case 3:
		TextureAsset(U"stage_3_back").draw(0, 0);
		break;
	case 4:
		TextureAsset(U"stage_4_back").draw(0, 0);
		break;
	case 5:
		TextureAsset(U"stage_5_back").draw(0, 0);
		break;
	case 6:
		TextureAsset(U"stage_6_back").draw(0, 0);
		break;
	case 7:
		TextureAsset(U"stage_7_back").draw(0, 0);
		break;
	case 8:
		TextureAsset(U"stage_8_back").draw(0, 0);
		break;
	case 9:
		TextureAsset(U"stage_9_back").draw(0, 0);
		break;
	default:
		break;
	}


	for (size_t i = 0; i < back_tile.size(); i++) {

			back_tile[i].draw(edit_scroll);		
	}



	Array<Rect> rect;//Lineにすると軽くなるかも

	for (int x = 0; x < 20; x++) {//縦線(16+4)//両サイド分
		rect.push_back(Rect((x-2) * 120, 0,1, 1080));
	
	}

	for (int y = 0; y < 9; y++) {//横線
		rect.push_back(Rect(-120, y * 120, 1920+240,1));
	}

	int line_adjust = edit_scroll % 120;

	for (size_t i = 0; i < rect.size(); i++) {
		
		Rect rected;
		rected = rect[i].movedBy(-line_adjust, 0);
		rected.draw(Palette::Red);

		
	}


	if (edit_display == 1) {//編集用のアイコンをだす

		TextureAsset(U"debug_edit_list").draw(60, 1080-150-10);

		TextureAsset(U"debug_edit_back").draw(10 +60+ (120 + 50) * 0, 1080 - 150 + 15 - 10);
		TextureAsset(U"debug_edit_pen").draw(10+60 +(120 + 50) * 1, 1080-150+15-10);
		TextureAsset(U"debug_edit_eraser").draw(10+60 + (120 + 50) * 2, 1080 - 150 + 15 - 10);
		TextureAsset(U"debug_edit_bukket").draw(10 + 60 + (120 + 50) * 3, 1080 - 150 + 15 - 10);
		TextureAsset(U"debug_edit_bukket_erase").draw(10 + 60 + (120 + 50) * 4, 1080 - 150 + 15 - 10);
		TextureAsset(U"debug_edit_save").draw(10 + 60 + (120 + 50) * 5, 1080 - 150 + 15 - 10);

		if (edit_select_item != 0) {//backではない
			TextureAsset(U"debug_edit_select").draw(10 + 60 + (120 + 50) * edit_select_item, 1080 - 150 + 15 - 10);
		}
		//cir.draw(Palette::Red);

		FontAsset(U"DebugMenuFont")(U"右クリックでツールボックスのON・OFF").draw(10, 10);
	}

	if (edit_saved_diplay_fade > 0) {//save表示
		FontAsset(U"DebugMenuFont2")(U"セーブしました").drawAt(1920/2, 1080/2,ColorF(1.0,edit_saved_diplay_fade));
		edit_saved_diplay_fade -= 0.0111;
	}

	
	
}
