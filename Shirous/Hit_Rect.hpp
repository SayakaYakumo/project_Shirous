#pragma once
#include"Siv3D.hpp"

class Hit_Rect {

public:
	Hit_Rect(int x,int y,int w,int h,int ad_x,int ad_y) {

		rect = Rect(x,y,w,h);

		adjust_x = ad_x;
		adjust_y = ad_y;
	}

	int get_adjust_x() { return adjust_x; }
	int get_adjust_y() { return adjust_y; }

	void update(int x, int y) { rect.x = x + adjust_x, rect.y + adjust_y; }

	Rect get_rect() { return rect; }

	void draw()const { rect.drawFrame(); }//デバッグ用

private:

	Rect rect;

	int adjust_x = 0;
	int adjust_y = 0;
};
