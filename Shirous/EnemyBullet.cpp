#include "EnemyBullet.hpp"
void EnemyBullet::Update(double deltaTime)
{
	pos.x -= deltaTime * speed;
	Draw();
}

void EnemyBullet::Draw()
{
	Circle(pos, 4).draw(Palette::White);
}
