#include"Game.hpp"

void Game::make_enemy_bullet(int e,int kind) {

	int x = 0;
	int y = 0;
	int r = 0;
	int speed = 0;
	int move = 0;
	double angle = 0;
	String shape = U"no_data";
	String color = U"no_data";
	String size = U"no_data";


	if (kind == 0) {//まっすぐショット

		x = gameEnemys[e].get_make_bullet_point().x;
		y = gameEnemys[e].get_make_bullet_point().y;
		r = 5;
		speed = 450;
		move = 0;
		angle = ToRadians(180);
		shape = U"circle";
		color = U"blue";
		size = U"s";

		gameEnemyBullet.push_back(EnemyBullet(x, y, r, speed, move, angle, shape, color, size));

		
	}
}
