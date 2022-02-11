#include "PlayerBullet.hpp"

void PlayerBullet::Update(double deltaTime)
{
	pos.x += deltaTime * speed;
	Draw();
}

void PlayerBullet::Draw()
{
	Circle(pos, 8).draw(Palette::Orange);
}
