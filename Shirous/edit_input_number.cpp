#include"Game.hpp"

void Game::update_edit_input_number() {

	int x_begin = 300;
	int y_begin = 200;

	class Cur_Box {
	public:
		Cur_Box(Rect rect_,int x_,int y_) {
			rect = rect_;
			x = x_;
			y = y_;
		}
		Rect rect;
		int x;
		int y;
	};

	Array<Cur_Box> cur_box;

	for (int x = 0; x < 3; x++) {
		for (int y = 0; y < 3; y++) {
			cur_box.push_back(Cur_Box(Rect(x_begin + x * (170 + 30), y_begin + (3-y) * (90 + 30),170,90),x,y));
		}
	}

	Array<Rect> rect;

	for (int x = 0; x < 3; x++) {
	
		rect.push_back(Rect(x_begin + x * (170 + 30), y_begin + (4) * (90 + 30), 170, 90));
	}

	Rect rect2(300,800,570,90);

	Array<Rect> rect3;

	
	rect3.push_back(Rect(x_begin + (3) * (170 + 30), y_begin + (1) * (90 + 30),90,210));
	rect3.push_back(Rect(x_begin + (3) * (170 + 30), y_begin + (3) * (90 + 30), 90, 210));

	Rect rect4(300+570+30, 800, 90, 90);


	int click_number = -1;
	edit_input_over = -1;

	for (size_t i = 0; i < cur_box.size();i++) {
		if (cur_box[i].rect.mouseOver()) {
			edit_input_over = cur_box[i].y * 3 + cur_box[i].x + 1;
			click_number = cur_box[i].y * 3 + cur_box[i].x + 1;
			Cursor::RequestStyle(CursorStyle::Hand);
		}
	}

	for (size_t i = 0; i < rect.size(); i++) {
		if (rect[i].mouseOver()) {
			click_number = 100 + i;
			edit_input_over = 100 + i;
			Cursor::RequestStyle(CursorStyle::Hand);
		}
	}

	if (rect2.mouseOver()) {
		edit_input_over = 1000;
		click_number = 1000;
		Cursor::RequestStyle(CursorStyle::Hand);
	}

	for (size_t i = 0; i < rect3.size(); i++) {
		if (rect3[i].mouseOver()) {
			click_number = 10000 + i;
			edit_input_over = 10000 + i;
			Cursor::RequestStyle(CursorStyle::Hand);
		}
	}

	if (rect4.mouseOver()) {
		click_number = 100000;
		edit_input_over = 100000;
		Cursor::RequestStyle(CursorStyle::Hand);
	}

	if (MouseL.down()) {

		if (click_number == 100) {//C
			edit_input_v = U"";
			edit_input_point = 0;
		}
		else if (click_number == 101) {//0
			if (edit_input_v.size() < 12) {
				int v = 0;

				edit_input_v += Format(v);
			}
		}
		else if (click_number == 102) {//.
			if (edit_input_point == 0&& edit_input_v.size()!=0) {
				edit_input_v += U".";
				edit_input_point = 1;
			}
		}
		else if (click_number == 1000) {//決定

			edit_input_end = 1;
		}
		else if (click_number == 10000) {//一つ戻す
			if (edit_input_v.size() >0 ) {
				edit_input_v.pop_back();
			}
		}
		else if (click_number == 10001) {//マイナス
			if (edit_input_v.size() == 0) {
				edit_input_v += U"-";
			}
		}
		else if (click_number == 100000) {//キャンセル
			edit_input_end = 2;
		}
		else if (click_number != -1) {
			if (edit_input_v.size() < 12) {
				int v = click_number;

				edit_input_v += Format(v);
			}
		}


	}

}

void Game::set_input_number(int v) {
	edit_input_v = Format(v);
}

void Game::draw_edit_input_number() {

	

	int x_begin = 300;
	int y_begin = 200;

	TextureAsset(U"debug_number_input").draw(x_begin, 150);

	//決定
	TextureAsset(U"debug_number_input").draw(x_begin, 800);

	if (edit_input_over == 1000) {
		TextureAsset(U"debug_number_input_select").draw(x_begin, 800);
	}

	FontAsset(U"DebugMenuFont6")(U"決定").draw(x_begin + 10, 800, Palette::Black);

	//キャンセル
	TextureAsset(U"debug_number_input_end").draw(x_begin+570+30, 800);

	if (edit_input_over == 100000) {
		TextureAsset(U"debug_number_input_end_select").draw(x_begin+570+ 30, 800);
	}


	//値表示
	FontAsset(U"DebugMenuFont6")(edit_input_v).draw(x_begin+10,150,Palette::Black);

	for (int x = 0; x < 3; x++) {
		for (int y = 0; y < 3; y++) {
			TextureAsset(U"debug_number_botton").draw(x_begin + x * (170 + 30), y_begin + (3-y) * (90 + 30));
			int v = y * 3 + x + 1;
			if (v == edit_input_over) {
				TextureAsset(U"debug_number_botton_select").draw(x_begin + x * (170 + 30), y_begin + (3 - y) * (90 + 30));
			}

			
			FontAsset(U"DebugMenuFont6")(v).draw(x_begin + x * (170 + 30)+60, y_begin + (3-y) * (90 + 30),Palette::Black);

			
		}
	}

	

	for (int x = 0; x < 3; x++) {
		TextureAsset(U"debug_number_botton").draw(x_begin + x * (170 + 30), y_begin + (4) * (90 + 30));


	}

	if (100 <= edit_input_over) {
		int x_ = edit_input_over - 100;
		TextureAsset(U"debug_number_botton_select").draw(x_begin + x_ * (170 + 30), y_begin + (4) * (90 + 30));
	}

	for (int x = 0; x < 3; x++) {

		String s = U"";

		switch (x)
		{
		case 0:
			s = U"C";
			break;
		case 1:
			s = U"0";
			break;
		case 2:
			s = U".";
			break;
		default:
			break;
		}


		FontAsset(U"DebugMenuFont6")(s).draw(x_begin + x * (170 + 30) + 60, y_begin + (4) * (90 + 30), Palette::Black);
	}

	//マイナス
	TextureAsset(U"debug_number_input_back").draw(x_begin + 3 * (170 + 30), y_begin + (1) * (90 + 30));

	if (edit_input_over == 10000) {
		TextureAsset(U"debug_number_input_back_select").draw(x_begin + 3 * (170 + 30), y_begin + (1) * (90 + 30));
	}

	//バック
	TextureAsset(U"debug_number_input_minus").draw(x_begin + 3 * (170 + 30), y_begin + (3) * (90 + 30));

	if (edit_input_over == 10001) {
		TextureAsset(U"debug_number_input_minus_select").draw(x_begin + 3 * (170 + 30), y_begin + (3) * (90 + 30));
	}

}
