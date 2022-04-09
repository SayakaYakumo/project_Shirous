#include"Game.hpp"

void Game::control_stage() {

	switch (stage_number)
	{
	case 0:
		control_stage_0();
		break;
	case 1:
		control_stage_1();
		break;
	case 2:
		control_stage_2();
		break;
	case 3:
		control_stage_3();
		break;
	case 4:
		control_stage_4();
		break;
	case 5:
		control_stage_5();
		break;
	case 6:
		control_stage_6();
		break;
	case 7:
		control_stage_7();
		break;
	case 8:
		control_stage_8();
		break;
	default:
		break;
	}
}

void Game::control_stage_0() {

	if (stage_scene == 0) {
		AudioAsset(U"stage_0").play();
		stage_scene++;
	}
}

void Game::control_stage_1() {

}

void Game::control_stage_2() {

}

void Game::control_stage_3() {

}

void Game::control_stage_4() {

}

void Game::control_stage_5() {

}

void Game::control_stage_6() {

}

void Game::control_stage_7() {

}

void Game::control_stage_8() {

}
