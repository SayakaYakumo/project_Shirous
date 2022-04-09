#pragma once
#include"Common.hpp"

class My_Effect
{
public:

	My_Effect(String, int, int);

	void update(double);
	void draw() const;

	double get_fade() { return _fade; }

private:

	String _kind;

	int _x = 0;
	int _y = 0;

	double _count = 0;

	double _fade = 1;

	double _size;

	double _size_up = 0;
	double _fade_delete = 0;

	double _adjust_x = 0;
	double _adjust_y = 0;

	double _wide = 0;
	double _high = 0;
};

