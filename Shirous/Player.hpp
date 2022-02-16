#pragma once

# include <Siv3D.hpp>

class Player 
{


private:

	double mySpeed = 550.0;

	double shot_cool_time = 0;

	double speed = 0.0;

	//unitより
	RectF rect;

	Texture texture;

	int count = 0;

	String name;

	

public:

	Player();
	~Player();

	void Update(double deltaTime);

	void Draw()const;

	void DrawFrame()const;

	void first();

	double get_cool_time() { return shot_cool_time; }

	void set_cool_time(double v) { shot_cool_time = v; }

	RectF get_rect() { return rect; }

	String get_name() { return name; }

};
