#pragma once
#include<Siv3D.hpp>

#define item_high_speed 720
#define item_middle_speed 540
#define item_low_speed 240

//順に、ボム、ライフ、オプション育成、スコア、パワーアップ。
//仮のものです
enum ItemType { Bomb_I, Life_I, Feed_I, Score_I, Power_I };

class Item
{
public:

	Item(Vec2 v, ItemType t);

	void Update(double deltaTime, Vec2 playerPos);
	void Draw()const;

	RectF get_rect() { return area; }

	String get_kind() { return name; }

	ItemType get_type() { return type; }

	bool alive = true;
private:

	RectF area;
	String name;
	ItemType type;
	Vec2 target;
	double speed;

	

	//蒐集ライン
	double collection_line = 1280;

	//出現時のバラ撒き時間
	double appear_time = 0.1;

	double appear_count = 0;

	//移動モードのシーケンス。あまり複数作らないとは思うが、色々増やしたい時もあるかもしれないので。
	//順に、その場に留まる、左に等速直線運動、プレイヤーに向かって移動
	enum moveMode{Mode_Stop, Mode_Left, Mode_Chase};

	moveMode mode;
};

