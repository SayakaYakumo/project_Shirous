#pragma once

#include"Siv3D.hpp"

class EmergeEnemy {

public:

	EmergeEnemy(String name, int x, int y, int move,int shot_pattern,int time) {

		_name = name;
		_x = x;
		_y = y;
		_move = move;
		_shot_pattern = shot_pattern;
		_time = time;
		
	}

	int get_x() { return _x; }

	int get_y() { return _y; }

	String get_name() { return _name; }

	int get_move() { return _move; }

	int get_time() { return _time; }

	int get_done() { return _done; }

	void set_done() { _done = 1; }

	int get_shot_pattern() { return _shot_pattern; }

private:

	int _x = 0;
	int _y = 0;
	String _name;
	int _move = 0;
	int _time = 0;
	int _shot_pattern = 0;

	int _done = 0;

};
