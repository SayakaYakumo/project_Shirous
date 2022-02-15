#include"Game.hpp"

void Game::draw_title() {

	TextureAsset(U"title_back").draw(0, 0);

	FontAsset(U"TitleFont")(U"～Press Z to start～").drawAt(1920/2, 850);

	

	FontAsset(U"DebugMenuFont")(U"デバッグ中・クリックでも始まります").drawAt(1920 / 2, 1000);
}
