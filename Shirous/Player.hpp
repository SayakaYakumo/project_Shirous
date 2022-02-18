#pragma once

# include <Siv3D.hpp>
# include "Player_Fish.hpp"

class Player 
{

private:

	Array<Fish> fish;

	int HP = 3;//３回被弾で自機がやられてオプションと交代
	double spawn_Timer = 0.0;
	double spawn_cool_time = 1.0;

public:

	Player();
	~Player();

	void Update(double deltaTime);

	void Draw()const;

	void DrawFrame()const;

	void first();

	void Spawn(double deltaTime);

	RectF get_rect() { return fish[0].get_rect(); }
	RectF get_rect(int i) { return fish[i].get_rect(); }

	String get_name() { return fish[0].get_name(); }
	String get_name(int i) { return fish[i].get_name(); }

	int get_fish_size() { return fish.size(); }

	double get_cool_time(int i) { return fish[i].get_cool_time(); }
	double get_shot_timer(int i) { return fish[i].get_shot_timer(); }

	//void set_cool_time(int i, double v) { fish[i].set_cool_time(v); }
	void reset_shot_timer(int i) { fish[i].reset_shot_timer(); }

};
