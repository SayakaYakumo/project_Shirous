#include"Game.hpp"

void Game::draw_title() {

	TextureAsset(U"title_back").draw(0, 0);

	FontAsset(U"TitleFont")(U"～Press Z to start～").drawAt(1920/2, 850);

}
