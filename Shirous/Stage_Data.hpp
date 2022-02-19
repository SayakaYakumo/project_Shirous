#pragma once
#include<Siv3D.hpp>

class Stage_Data {

public:

	void set_wide(int v) { _wide = v; }

	void set_speed(int v) { _speed = v; }

	int get_wide() { return _wide; }

	int get_speed() { return _speed; }

	// シリアライズに対応させるためのメンバ関数を定義する
	template <class Archive>
	void SIV3D_SERIALIZE(Archive& archive)
	{
		archive(_wide,_speed);
	}


private:

	

	int _wide = 0;

	int _speed = 0;

};
