#include"Game.hpp"

void Game::draw_pose() const {

	FontAsset(U"PoseFont")(U"-Pose-").drawAt(1920 / 2, 1080 / 2);

	if (debug != 1) {//デバッグ中でない
		TextureAsset(U"pose_back").draw(0,0,ColorF(1.0,0.3));//ゲーム画面を少し隠す
	}
	else if (debug == 1) {
		FontAsset(U"DebugMenuFont")(U"デバッグ中・Zでメニューに戻ります").drawAt(1920 / 2, (1080+800) / 2);
	}
}
