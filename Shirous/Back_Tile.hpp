#pragma once
#include<Siv3D.hpp>

class Back_Tile {

public:

	Back_Tile(int x_,int y_,int kind_) {
		x = x_;
		y = y_;
		kind = kind_;
	}

	void draw(int scroll)const{

		int display_x = kind % 10;
		int display_y = kind / 10;

		TextureAsset(U"back_tile")(display_x * 120, display_y * 120, 120, 120).draw(x * 120 - scroll, y * 120);

	}

	int get_x() { return x; }
	int get_y() { return y; }
	int get_kind()const { return kind; }

	void set_x(int v) { x = v; }
	void set_y(int v) { y = v; }
	void set_kind(int v) { kind = v; }


private:

	int x = 0;
	int y = 0;
	int kind = 0;

};
