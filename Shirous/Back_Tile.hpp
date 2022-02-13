#pragma once
#include<Siv3D.hpp>

class Back_Tile {

public:

	Back_Tile(){}

	Back_Tile(int x_,int y_,int kind_) {
		x = x_;
		y = y_;
		kind = kind_;
	}

	void draw(int scroll)const{

		if (kind != -1) {

			int display_x = kind % 10;
			int display_y = kind / 10;

			TextureAsset(U"back_tile")(display_x * 120, display_y * 120, 120, 120).draw(x * 120 - scroll, y * 120);
		}

		if (edit_kind_x != -1&&edit_kind_y!=-1) {

			int display_x = kind % 10;
			int display_y = kind / 10;

			TextureAsset(U"back_tile")(display_x * 120, display_y * 120, 120, 120).draw(x * 120 - scroll, y * 120,ColorF(1.0,0.7));
		}

	}

	void draw_edit(int scroll)const {

		
	}

	int get_x() { return x; }
	int get_y() { return y; }
	int get_kind()const { return kind; }
	int get_edit_kind_x() { return edit_kind_x; }
	int get_edit_kind_y() { return edit_kind_y; }

	void set_x(int v) { x = v; }
	void set_y(int v) { y = v; }
	void set_kind(int v) { kind = v; }
	void set_edit_kind_x(int v) { edit_kind_x = v; }
	void set_edit_kind_y(int v) { edit_kind_y = v; }

	void reset_edit_kind() { edit_kind_x = -1; edit_kind_y = -1; }

	// シリアライズに対応させるためのメンバ関数を定義する
	template <class Archive>
	void SIV3D_SERIALIZE(Archive& archive)
	{
		archive(x,y,kind);
	}




private:

	int x = 0;
	int y = 0;
	int kind = -1;

	int edit_kind_x = -1;
	int edit_kind_y = -1;

};
