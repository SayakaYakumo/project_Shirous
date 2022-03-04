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
		r = 30;
		speed = 450;
		move = 0;
		angle = ToRadians(180);
		shape = U"circle";
		color = U"blue";
		size = U"s";

		gameEnemyBullet.push_back(EnemyBullet(x, y, r, speed, move, angle, shape, color, size));

		
	}
	else if (kind == 1) {//自機狙い

		x = gameEnemys[e].get_make_bullet_point().x;
		y = gameEnemys[e].get_make_bullet_point().y;
		r = 30;
		speed = 450;
		move = 0;
		angle = get_player_angle(e);
		shape = U"circle";
		color = U"blue";
		size = U"s";

		gameEnemyBullet.push_back(EnemyBullet(x, y, r, speed, move, angle, shape, color, size));
	}
}


double Game::get_player_angle(int e) {

	int p_x = gamePlayer.get_rect().x+ gamePlayer.get_rect().w/2;
	int p_y = gamePlayer.get_rect().y+ gamePlayer.get_rect().h/2;

	int e_x = gameEnemys[e].get_rect().x + gameEnemys[e].get_rect().w/2;
	int e_y = gameEnemys[e].get_rect().y + gameEnemys[e].get_rect().h / 2;

	return atan2(p_y - e_y, p_x - e_x);
}
