#pragma once
#include "Bullet.hpp"
class EnemyBullet :
	public Bullet
{

private:

public:

	EnemyBullet(Vec2 setPos) {
		pos = setPos;
		speed = 300.0;
	}
	~EnemyBullet() {

	}

	bool BulletEnd() const {
		return pos.x < -100;
	}


	void Update(double deltaTime);

	void Draw();

};
