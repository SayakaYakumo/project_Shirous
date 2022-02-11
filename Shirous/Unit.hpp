#pragma once
# include <Siv3D.hpp>
class Unit
{
public:

	double speed = 0.0;

	Vec2 pos;

	Texture texture;

public:

	Unit()
	{
	}

	~Unit()
	{


	}

	bool MyHitCheck(Vec2 _bulletPos, double _r = 40);
};
