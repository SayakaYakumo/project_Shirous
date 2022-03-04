#pragma once
#include"Siv3D.hpp"

class Hit_Rect {

public:
	Hit_Rect(Rect rect) {
		_adjust_x = rect.x;
		_adjust_y = rect.y;
		_rect = Rect(-10000,-10000,rect.w,rect.h);
	}

	void update(int enemy_x, int enemy_y) { _rect.x = enemy_x + _adjust_x; _rect.y = enemy_y + _adjust_y; }

	Rect get_rect() { return _rect; }

	void draw()const { _rect.drawFrame(); }//デバッグ用

private:

	Rect _rect;

	int _adjust_x = 0;
	int _adjust_y = 0;
	int _w = 0;
	int _h = 0;
};
