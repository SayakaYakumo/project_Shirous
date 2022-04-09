#include"Game.hpp"

void Game::play_bgm() {

}

void Game::play_se(String name) {

	double volume = double(se_volume) / double(10);

	AudioAsset(name).playOneShot(volume);
}

void Game::play_se_main() {

	double volume = double(se_volume) / double(10);

	for (size_t s = 0; s < se_will.size(); s++) {

		int kind = se_will[s];

		if (se_lock[kind] <= 0) {
			AudioAsset(se[kind]).playOneShot(volume);
			se_lock[kind] = 0.1;
		}
	}
}

void Game::update_se(double deltaTime) {

	se_will.clear();

	for (size_t s = 0; s < se_lock.size(); s++) {
		if (se_lock[s] > 0) {
			se_lock[s] -= deltaTime;
		}
	}
}

void Game::set_se(int kind) {
	se_will << kind;
}
