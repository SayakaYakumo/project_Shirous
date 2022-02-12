#pragma once

# include <Siv3D.hpp>
# include"Unit.hpp"
class Player :
	public Unit
{


private:

	double mySpeed = 550.0;

	double shot_cool_time = 0;

public:

	Player();
	~Player();

	void Update(double deltaTime);

	void Draw()const;

	//ƒVƒ‡ƒbƒg
	void Shot();

	bool MyHitCheck(Vec2 enemyBulletPos);

	void first();

	double get_cool_time() { return shot_cool_time; }

	void set_cool_time(double v) { shot_cool_time = v; }

	Rect get_rect() { return rect; }

};
