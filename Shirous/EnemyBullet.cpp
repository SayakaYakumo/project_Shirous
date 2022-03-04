#include "EnemyBullet.hpp"
void EnemyBullet::Update(double deltaTime)
{
	
	circle.x += cos(angle) * speed * deltaTime;
	circle.y += sin(angle) * speed * deltaTime;
}

void EnemyBullet::Draw()const
{
	String texture_name = U"bullet_" + shape + U"_" + color + U"_" + size;

	TextureAsset(texture_name).draw(circle.x - circle.r , circle.y - circle.r);

	//Print << U"x::" << circle.x;
	//Print << U"y::" << circle.y;
}

void EnemyBullet::Draw_Frame()const {

	circle.drawFrame(5);

}
