#include "stdafx.h"
#include "My_Effect.hpp"

My_Effect::My_Effect(String kind,int x,int y) {
	_kind = kind;
	_x = x;
	_y = y;


	if (U"bullet_circle_red_s_effect" == _kind) {

		_fade = 0.8;
		_fade_delete = _fade * 1;
		_size = 1;
		_size_up = 2;

		_wide = 60;
		_high = 60;

		_adjust_x = _wide * _size / 2;
		_adjust_y = _high * _size / 2;
	}
}

void My_Effect::update(double deltaTime) {
	_count += deltaTime;

	_fade -= _fade_delete * deltaTime;
	_size += _size_up*deltaTime;

	_adjust_x = (_wide * _size / 2);
	_adjust_y = (_high * _size / 2);
}

void My_Effect::draw() const {

	

	TextureAsset(_kind).scaled(_size).draw(_x-_adjust_x, _y-_adjust_y, ColorF(1.0, _fade));
	
}
