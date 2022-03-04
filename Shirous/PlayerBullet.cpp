#include "PlayerBullet.hpp"

void PlayerBullet::Update(double deltaTime)
{

	circle.x += cos(angle) * speed*deltaTime;
	circle.y += sin(angle) * speed* deltaTime;
}

void PlayerBullet::Draw()const
{
	String texture_name = U"bullet_" + shape + U"_" + color + U"_" + size;

	TextureAsset(texture_name).draw(circle.x-circle.r, circle.y - circle.r ,ColorF(1.0,0.7));

	
}

void PlayerBullet::Draw_Frame()const {

	circle.drawFrame(5);

}
