#pragma once
#include "Bullet.hpp"
class EnemyBullet :
	public Bullet
{

private:



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

	Circle get_circle() { return circle; }
};
