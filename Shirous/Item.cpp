#include "stdafx.h"
#include "Item.hpp"

void Item::ini(int x,int y) {

	if (_name == U"赤"&&_name==U"青"&&_name==U"緑") {
		_rect = Rect(x,y,50,50);
	}

}

void Item::update() {

}

void Item::draw() {
	String texture_name = U"item_" + _name;

	TextureAsset(texture_name).draw(_rect.x, _rect.y);
}
