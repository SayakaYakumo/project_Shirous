#pragma once
#include"Siv3D.hpp"

class Hit_Rect {

public:
	Hit_Rect(Rect rect) {
		_adjust_x = rect.x;
		_adjust_y = rect.y;
	}

	int get_adjust_x() { return _adjust_x; }
	int get_adjust_y() { return _adjust_y; }

	void update(int x, int y) { _rect.x = x + _adjust_x, _rect.y=y + _adjust_y; }

	Rect get_rect() { return _rect; }

	void draw()const { _rect.drawFrame(); }//デバッグ用

private:

	Rect _rect;

	int _adjust_x = 0;
	int _adjust_y = 0;
};
