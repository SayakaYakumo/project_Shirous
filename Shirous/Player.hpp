#pragma once

# include <Siv3D.hpp>
# include"Unit.hpp"
class Player :
	public Unit
{


private:

	double mySpeed = 550.0;


public:

	Player();
	~Player();

	void Update(double deltaTime);

	void Draw();

	//ƒVƒ‡ƒbƒg
	void Shot();

	bool MyHitCheck(Vec2 enemyBulletPos);

};
