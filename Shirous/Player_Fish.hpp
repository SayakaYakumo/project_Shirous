#pragma once

# include <Siv3D.hpp>

class Fish
{


private:

	double mySpeed = 550.0;

	double shot_cool_time = 0.2;

	double shot_timer = 0;

	double speed = 0.0;

	Vec2 option_speed = Vec2(0, 0);

	double option_pos_timer = 0.0;//群れっぽい上下の振れ幅に使う

	double option_slow_timer = 0.0;//移動速度の減衰に使う

	double ika_move_timer = 0.0;//イカの動き（マリオのゲッソー意識）

	//unitより
	RectF rect;

	Texture texture;

	int count = 0;

	String name;



public:

	Fish();
	Fish(RectF rect);
	Fish(String name, RectF rect);
	~Fish();

	void myUpdate(double deltaTime);

	void opUpdate(int i, RectF player, double deltaTime);

	void opMove(int i, RectF player, double deltaTime);

	void Draw()const;

	void DrawFrame()const;

	void first();
	void first(RectF rect);
	void first(String name, RectF rect);

	double get_cool_time() { return shot_cool_time; }
	double get_shot_timer() { return shot_timer; }

	void set_cool_time(double v) { shot_cool_time = v; }
	void reset_shot_timer() { shot_timer = 0; }

	RectF get_rect() { return rect; }

	String get_name() { return name; }

};
