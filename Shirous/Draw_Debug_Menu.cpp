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
	default:
		break;
	}


}


void Game::draw_debug_menu_stage_select() {

for (int x = 0; x < 5; x++) {
		for (int y = 0; y < 2; y++) {
			TextureAsset(U"debug_menu_rect_frame").draw(195 + x * (250 + 70), 200 + y * (250 + 100));

			if (debug_menu_cur_x == x&& debug_menu_cur_y == y) {
				TextureAsset(U"debug_menu_rect_select_frame").draw(195 + x * (250 + 70), 200 + y * (250 + 100));
			}


				String number = Format(y * 5 + x);

				FontAsset(U"DebugMenuFont")(U"ステージ").draw(195 + x * (250 + 70)+40, 200 + y * (250 + 100)+10);
				FontAsset(U"DebugMenuFont2")(number).draw(195 + x * (250 + 70)+90, 200 + y * (250 + 100)+70);

			
		}
	}

}

void Game::draw_debug_menu_mode_select() {

	FontAsset(U"DebugMenuFont3")(U"Stage "+Format(debug_stage_number)).drawAt(1920 / 2, 200);


	for (int x = 0; x < 3; x++) {
		

		TextureAsset(U"debug_menu_rect_frame").draw(515 + x * (250 + 70),600);

		if (debug_menu_2_cur_x == x) {
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
