#pragma once
#include<Siv3D.hpp>
class EnemyBullet 
{

private:

	double speed = 0;

	int move = 0;

	Circle circle;

	String color;

	String shape;

	String size;//circle.rとは異なる

	double angle = 0;

	int power = 1;

public:

	EnemyBullet(int x, int y, int r, int speed_, int move_,double angle_, String shape_, String color_, String size_) {
		circle = Circle(x, y, r);
		speed = speed_;
		move = move_;
		angle = angle_;
		shape = shape_;
		color = color_;
		size = size_;
	}

	
	~EnemyBullet() {

	}

	


	void Update(double deltaTime);

	void Draw()const;

	void Draw_Frame()const;

	Circle get_circle() { return circle; }
};
