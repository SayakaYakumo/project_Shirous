#include"Game.hpp"


void Game::change_scene(int scene_number) {

	change_scene_number = scene_number;

	change_scene_count = 60;
}

void Game::update_change_scene() {

	//change_scene実行中
	if (change_scene_count > 0) {

		change_scene_count--;
	
		if (change_scene_type == 0) {//60

			if (change_scene_count > 30) {//暗くする
				change_scene_screen_fade += 0.032;
			}
			else if (change_scene_count == 30) {

				//scene切り替え
				if (change_scene_number != -1) {
					game_scene = change_scene_number;

					if (change_scene_number == 2) {//Playシーンの場合データを読み込み
					
						play_load(stage_number);
					}

					if (change_scene_number == 3) {//

					}
				}

			}
			else if (change_scene_count < 30) {//明るくする
				change_scene_screen_fade -= 0.032;
			}
		}
		
	}

	//change_scene終了
	if (change_scene_count == 0) {

		change_scene_screen_fade = 0;//小数の残りを0にする
	}
}

void Game::draw_change_scene() {

	TextureAsset(U"change_scene_fade").draw(0,0,ColorF(1.0, change_scene_screen_fade));



}





