﻿#include "Player.hpp"

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
			fish[i].opUpdate(i, fish[0].get_rect(), deltaTime);
		}
	}

	Spawn(deltaTime);

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

void Player::Spawn(double deltaTime)
{
	if (spawn_cool_time <=0 && KeyC.pressed())
	{
		spawn_Timer += deltaTime;
	}
	else spawn_Timer = 0.0;

	if (spawn_Timer > 2.0)
	{
		fish.push_back(Fish(fish[0].get_rect()));
		spawn_cool_time = 2.0;
	}
	if (spawn_cool_time > 0) spawn_cool_time -= deltaTime;
}


void Player::start() {
	
}
