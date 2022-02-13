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
	default:
		break;
	}
	
}

void Game::update_debug_menu_stage_select() {

	if (KeyLeft.down()) {
		debug_menu_cur_x--;
	}
	else if (KeyRight.down()) {
		debug_menu_cur_x++;
	}

	if (debug_menu_cur_x < 0) {
		debug_menu_cur_x = 0;
	}

	if (debug_menu_cur_x > 4) {
		debug_menu_cur_x = 4;
	}


	if (KeyUp.down()) {
		debug_menu_cur_y--;
	}
	else if (KeyDown.down()) {
		debug_menu_cur_y++;
	}

	if (debug_menu_cur_y < 0) {
		debug_menu_cur_y = 0;
	}

	if (debug_menu_cur_y > 1) {
		debug_menu_cur_y = 1;
	}


	if (KeyZ.down()) {
		debug_stage_number = debug_menu_cur_y * 5 + debug_menu_cur_x;

		debug_menu_2_cur_x = 1;

		debug_menu_scene = 1;


	
	}

}

void Game::update_debug_menu_mode_select() {

	if (KeyLeft.down()) {
		debug_menu_2_cur_x--;
	}
	else if (KeyRight.down()) {
		debug_menu_2_cur_x++;
	}

	if (debug_menu_2_cur_x < 0) {
		debug_menu_2_cur_x = 0;
	}

	if (debug_menu_2_cur_x > 2) {
		debug_menu_2_cur_x = 2;
	}


	if (KeyZ.down()) {
		
		switch (debug_menu_2_cur_x)
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
