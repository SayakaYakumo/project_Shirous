#pragma once
# include <Siv3D.hpp>
class Unit
{
public:

	double speed = 0.0;

	Rect rect;

	Texture texture;

	int count = 0;

	String name;

public:

	Unit()
	{
		rect = Rect(0,0,0,0);

	}

	~Unit()
	{


	}

	
};
