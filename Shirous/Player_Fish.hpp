﻿#pragma once

# include <Siv3D.hpp>

class Fish
{


private:

	double mySpeed = 550.0;

	double shot_cool_time = 0;

	double shot_timer = 0;

	double speed = 0.0;

	Vec2 option_speed = Vec2(0, 0);

	//unitより
	RectF rect;

	Texture texture;

	int count = 0;

	String name;



public:

	Fish();
	~Fish();

	void myUpdate(double deltaTime);

	void opUpdate(RectF player, double deltaTime);

	void Draw()const;

	void DrawFrame()const;

	void first();

	double get_cool_time() { return shot_cool_time; }

	void set_cool_time(double v) { shot_cool_time = v; }

	RectF get_rect() { return rect; }

	String get_name() { return name; }

};
