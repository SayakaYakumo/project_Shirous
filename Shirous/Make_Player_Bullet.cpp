#include"Game.hpp"

void Game::make_player_bullet(int i) {

	String name = gamePlayer.get_name(i);

	    int x = 0;
		int y = 0;
		int r = 0;
		int speed = 0;
		int move = 0;
		double angle = 0;
		String shape=U"no_data";
		String color=U"no_data";
		String size=U"no_data";
		bool pen = false;

	if (name == U"シラス") {

		x = gamePlayer.get_rect(i).x;
		y = gamePlayer.get_rect(i).y;

		r = 30;
		speed = 700;
		move = 0;
		angle = ToRadians(0);
		shape = U"circle";
		color = U"red";
		size = U"s";

		gamePlayerBullet.push_back(PlayerBullet(x,y,r,speed,move,angle,shape,color,size));

		gamePlayer.reset_shot_timer(i);
	}
	if (name == U"アンコウ") {

		x = gamePlayer.get_rect(i).x;
		y = gamePlayer.get_rect(i).y;

		r = 30;
		speed = 700;
		move = 0;
		angle = ToRadians(0);
		shape = U"circle";
		color = U"red";
		size = U"s";

		gamePlayerBullet.push_back(PlayerBullet(x, y, r, speed, move, angle, shape, color, size));

		gamePlayer.reset_shot_timer(i);
	}
	if (name == U"ハリセンボン") {

		x = gamePlayer.get_rect(i).x;
		y = gamePlayer.get_rect(i).y;

		r = 30;
		speed = 700;
		move = 0;
		shape = U"circle";
		color = U"red";
		size = U"s";

		angle = ToRadians(20);
		gamePlayerBullet.push_back(PlayerBullet(x, y, r, speed, move, angle, shape, color, size));

		angle = ToRadians(-20);
		gamePlayerBullet.push_back(PlayerBullet(x, y, r, speed, move, angle, shape, color, size));

		gamePlayer.reset_shot_timer(i);
	}
	if (name == U"タツノオトシゴ") {

		x = gamePlayer.get_rect(i).x;
		y = gamePlayer.get_rect(i).y;

		r = 30;
		speed = 1200;
		move = 0;
		angle = ToRadians(0);
		shape = U"circle";
		color = U"red";
		size = U"s";
		pen = true;

		gamePlayerBullet.push_back(PlayerBullet(x, y, r, speed, move, angle, shape, color, size, pen, 3));

		gamePlayer.reset_shot_timer(i);
	}
	if (name == U"イカ") {

		x = gamePlayer.get_rect(i).x;
		y = gamePlayer.get_rect(i).y;

		r = 30;
		speed = 800;
		move = 0;
		angle = ToRadians(0);
		shape = U"circle";
		color = U"red";
		size = U"s";

		gamePlayerBullet.push_back(PlayerBullet(x, y, r, speed, move, angle, shape, color, size));

		gamePlayer.reset_shot_timer(i);
	}

}
