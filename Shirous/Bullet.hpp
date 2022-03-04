#pragma once

# include <Siv3D.hpp>
class Bullet
{

public:



	double speed=0;

	int move=0;

	Circle circle;

	String color;

	String shape;

	String size;//circle.rとは異なる

	double angle=0;


	Bullet() {
		circle = Circle(0, 0, 0);
	}
	~Bullet() {

	}

	

	

};
