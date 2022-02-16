#include"Game.hpp"

void Game::draw_gameover()const {

	//  文字表示
	gameoverfont(U"Press Key A to continue").drawAt(Scene::Center(), Palette::Black);
}
