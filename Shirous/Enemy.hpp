﻿#pragma once

# include <Siv3D.hpp>
# include"Unit.hpp"
# include"Hit_Rect.hpp"

class Enemy :
	public Unit
{


private:

	double mySpeed = 100.0;

	int move_pattern = 0;

	int make_bullet_flag = -1;

	int shot_pattern = 0;

	Vec2 make_bullet_point;

	int make_bullet_point_adjust_x;

	int make_bullet_point_adjust_y;


	double shot_count = 0;

	double move_count = 0;

	int hp = 3;

	Array<Hit_Rect> hit_rect;

public:

	Enemy(String,int,int,int,int);//名前、ｘ、ｙ、移動パターン,ショットパターン
	~Enemy();

	void Update(double deltaTime);

	void Draw()const;

	void move(double);

	void move_0(double);
	void move_1(double);
	void move_2(double);
	void move_3(double);
	void move_4(double);
	void move_5(double);
	void move_6(double);

	void shot();

	void shot_0();
	void shot_1();
	void shot_2();
	void shot_3();
	void shot_4();
	void shot_5();
	void shot_6();

	int get_bullet_flag() { return make_bullet_flag;}

	void reset_bullet_flag() { make_bullet_flag = -1; }

	Rect get_rect() { return rect; }

	Vec2 get_make_bullet_point() {return make_bullet_point; }

	void damage(int v) { hp -= v; }

	int get_hp() { return hp; }

	int get_hit_rect_size() { return (int)hit_rect.size(); }

	Rect get_hit_rect(int v) { return hit_rect[v].get_rect(); }


};
