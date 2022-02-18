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

	if (name == U"シラス") {


		x = gamePlayer.get_rect(i).x;
		y = gamePlayer.get_rect(i).y;
		r = 30;
		speed = 1000;
		move = 0;
		angle = ToRadians(0);
		shape = U"circle";
		color = U"red";
		size = U"s";

		gamePlayerBullet.push_back(PlayerBullet(x,y,r,speed,move,angle,shape,color,size));

		gamePlayer.set_cool_time(i, 0.2);
	}

}
