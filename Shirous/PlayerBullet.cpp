#include "PlayerBullet.hpp"

void PlayerBullet::Update(double deltaTime)
{

	circle.x += cos(angle) * speed*deltaTime;
	circle.y += sin(angle) * speed* deltaTime;
}

void PlayerBullet::Draw()const
{
	String texture_name = U"bullet_" + shape + U"_" + color + U"_" + size;

	TextureAsset(texture_name).draw(circle.x-(circle.r/2), circle.y - (circle.r / 2));

	
}
