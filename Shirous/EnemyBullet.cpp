#include "EnemyBullet.hpp"
void EnemyBullet::Update(double deltaTime)
{
	
	circle.x += cos(angle) * speed * deltaTime;
	circle.y += sin(angle) * speed * deltaTime;
}

void EnemyBullet::Draw()const
{
	String texture_name = U"bullet_" + shape + U"_" + color + U"_" + size;

	TextureAsset(texture_name).draw(circle.x - (circle.r / 2), circle.y - (circle.r / 2));

	//Print << U"x::" << circle.x;
	//Print << U"y::" << circle.y;
}
