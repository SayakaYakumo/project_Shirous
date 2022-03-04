#pragma once

#include"Siv3D.hpp"

class EmergeEnemy {

public:

	EmergeEnemy(){}

	EmergeEnemy(String name,String name2, int x, int y,double time) {

		_name = name;
		_name_2 = name2;
		_x = x;
		_y = y;
		_time = time;
		
	}

	int get_x() { return _x; }

	int get_y() { return _y; }

	String get_name() { return _name; }

	String get_name_2() { return _name_2; }

	double get_time() { return _time; }

	int get_done() { return _done; }

	void set_done() { _done = 1; }

	void set_edit_mark(int v) { _edit_mark = v; }

	int get_edit_mark() { return _edit_mark; }

	// シリアライズに対応させるためのメンバ関数を定義する
	template <class Archive>
	void SIV3D_SERIALIZE(Archive& archive)
	{
		archive(_name, _x, _y,_time);
	}

private:

	int _x = 0;
	int _y = 0;
	String _name;
	String _name_2;
	double _time = 0;


	int _done = 0;


	int _edit_mark = 0;

};
