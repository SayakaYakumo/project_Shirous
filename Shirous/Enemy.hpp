#pragma once

# include <Siv3D.hpp>
#include"Player.hpp"
# include"Hit_Rect.hpp"
# include"Item.hpp"
#include"Drop_Item.hpp"

class Enemy 	
{

private:

	

	

	int make_bullet_flag = -1;

	

	Vec2 make_bullet_point;

	int make_bullet_point_adjust_x;
	int make_bullet_point_adjust_y;

	int act_scene = 0;
	int shot_scene = 0;
	int move_scene = 0;

	double act_count = 0;
	double shot_count = 0;
	double move_count = 0;


	int hp = 3;
	int act_pattern = 0;
	int move_pattern = 0;
	int shot_pattern = 0;

	int score = 0;

	Array<Hit_Rect> hit_rect;

	Array<Drop_Item>drop_item;

	//unitより
	RectF rect;

	Texture texture;

	int count = 0;

	double count_2 = 0;

	String name;

    double speed = 100.0;

public:

	Enemy(String,int,int,int,int,int,int,Array<Rect>);//名前、ｘ、ｙ、体力,行動パータン,移動パターン,ショットパターン
	~Enemy();

	void Update(double deltaTime, std::shared_ptr<Player>& player, bool& is_intersect);

	void Draw()const;

	void DrawFrame()const;

	void act(double);

	void act_0(double);
	void act_1(double);
	void act_2(double);
	void act_3(double);
	void act_4(double);
	void act_5(double);
	void act_6(double);

	void move(double, std::shared_ptr<Player>& player,bool&);

	void move_0(double, std::shared_ptr<Player>& player);
	void move_1(double, std::shared_ptr<Player>& player);
	void move_2(double, std::shared_ptr<Player>& player);
	void move_3(double, std::shared_ptr<Player>& player,bool&);
	void move_4(double, std::shared_ptr<Player>& player);
	void move_5(double, std::shared_ptr<Player>& player);
	void move_6(double, std::shared_ptr<Player>& player);

	void shot(std::shared_ptr<Player>& player);

	void shot_0(std::shared_ptr<Player>& player);
	void shot_1(std::shared_ptr<Player>& player);
	void shot_2(std::shared_ptr<Player>& player);
	void shot_3(std::shared_ptr<Player>& player);
	void shot_4(std::shared_ptr<Player>& player);
	void shot_5(std::shared_ptr<Player>& player);
	void shot_6(std::shared_ptr<Player>& player);

	int get_bullet_flag() { return make_bullet_flag;}

	void reset_bullet_flag() { make_bullet_flag = -1; }

	RectF get_rect() { return rect; }

	Vec2 get_make_bullet_point() {return make_bullet_point; }

	void damage(int v) { hp -= v; }

	int get_hp() { return hp; }

	int get_hit_rect_size() { return (int)hit_rect.size(); }

	Rect get_hit_rect(int v) { return hit_rect[v].get_rect(); }

	int get_score() { return score; }

	Array<Item> get_items();
};
