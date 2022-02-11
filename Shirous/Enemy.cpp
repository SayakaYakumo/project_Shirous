#include "Enemy.hpp"





Enemy::Enemy()
{
	speed = mySpeed;
	texture = Texture(Emoji(U"🐡"));
	pos = RandomVec2( 2020, { 50, 1030 });
}

Enemy::~Enemy()
{


}

void Enemy::Update(double deltaTime, bool& gameover)
{
	pos.x -= deltaTime * speed;

	if (pos.x < -100)
	{
		
	}
	Draw();
}

void Enemy::Draw()
{
	texture.resized(60).drawAt(pos);
}
