#pragma once
#pragma once
#include "Bullet.hpp"
class PlayerBullet :
	public Bullet
{
private:

public:

	PlayerBullet(Vec2 setPos) {
		pos = setPos;
		speed = 500.0;
	}
	~PlayerBullet() {

	}

	bool BulletEnd() const {
		return pos.x > 1970;
	}


	void Update(double deltaTime);

	void Draw();
};
