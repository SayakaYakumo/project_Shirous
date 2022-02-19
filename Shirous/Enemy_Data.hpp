#pragma once
#include<Siv3D.hpp>
class Enemy_Data
{
public:

	Enemy_Data(){
	
	}

	Enemy_Data(String name,String name2,int hp,int act,int move,int shot,int speed,int score) {

		_name = name;
		_name2 = name2;
		_hp = hp;
		_act = act;
		_move = move;
		_shot = shot;
		_speed = speed;
		_score = score;
	}

	String get_name() { return _name; }
	String get_name2() { return _name2; }
	int get_hp() { return _hp; }
	int get_act() { return _act; }
	int get_move() { return _move; }
	int get_shot() { return _shot; }

	

	int get_rect_size() { return _rect.size(); }
	Rect get_rect(int v) { return _rect[v]; }

	void plus_rect(Rect v) { _rect.push_back(v); }

	void back_rect() {
		if (_rect.size() > 0) {//配列が空でない
			_rect.pop_back();
		}
	}

	void set_name(String n) { _name = n; }
	void set_name2(String n) { _name2 = n; }
	void set_hp(int v) { _hp = v; }
	void set_act(int v) { _act = v; }
	void set_move(int v) { _move = v; }
	void set_shot(int v) { _shot = v; }

	Array<Rect>get_rects() { return _rect; }

	// シリアライズに対応させるためのメンバ関数を定義する
	template <class Archive>
	void SIV3D_SERIALIZE(Archive& archive)
	{
		archive(_name,_name2,_hp,_act,_move,_shot,_speed,_score,_item,_rect);
	}


private:
	String _name;
	String _name2;
	int _hp = 0;
	int _act = 0;
	int _move = 0;
	int _shot = 0;
	int _speed = 0;
	int _score = 0;
	Array<String>_item;
	Array<Rect> _rect;


};

