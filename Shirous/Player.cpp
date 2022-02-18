#include "Player.hpp"

Player::Player()
{

	fish.push_back(Fish());
	fish.push_back(Fish());

}

Player::~Player()
{

}

void Player::Update(double deltaTime)
{
	fish[0].myUpdate(deltaTime);
	if (fish.size() >= 2)
	{
		for (int i = 1; i < fish.size(); i++)
		{
			fish[i].opUpdate(fish[0].get_rect(), deltaTime);
		}
	}

}

void Player::Draw()const
{
	// 自機の描画

	for (int i = 0; i < fish.size(); i++)
	{
		fish[i].Draw();
	}

}

void Player::DrawFrame()const
{
	for (int i = 0; i < fish.size(); i++)
	{
		fish[i].DrawFrame();
	}
}

void Player::Spawn()
{

}

void Player::first() {
	
}
