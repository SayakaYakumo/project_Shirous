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
			fish[i].opUpdate(i, fish[0].get_rect(), deltaTime);
		}
	}

	Spawn2(deltaTime);

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
		fish.push_back(Fish(Sample({ U"シラス", U"アンコウ", U"ハリセンボン"}), fish[0].get_rect()));
		spawn_cool_time = 2.0;
	}
	if (spawn_cool_time > 0) spawn_cool_time -= deltaTime;
}

//助案のオプション生成(押す長さによって消費量とオプションが決まる)
void Player::Spawn2(double deltaTime)
{
	if (spawn_cool_time > 0) spawn_cool_time -= deltaTime;

	if (spawn_cool_time <= 0 && KeyC.pressed())
	{
		useFeed += deltaTime * 20.0;
		if (useFeed >= feed) useFeed = feed;
	}

	if (KeyC.up() || (KeyC.pressed() && useFeed == feed)) {
		if (useFeed >= 30) {
			fish.push_back(Fish(U"ハリセンボン", fish[0].get_rect()));
		}
		else if (useFeed >= 20) {
			fish.push_back(Fish(U"アンコウ", fish[0].get_rect()));
		}
		else if (useFeed >= 10) {
			fish.push_back(Fish(U"シラス", fish[0].get_rect()));
		}

		if (useFeed >= 10) feed -= useFeed;
		spawn_cool_time = 2.0;
		useFeed = 0;
	}

	if (spawn_Timer > 2.0)
	{
		fish.push_back(Fish(Sample({ U"シラス", U"アンコウ", U"ハリセンボン" }), fish[0].get_rect()));
		
	}
	
}


void Player::start() {
	
}

void Player::damage() {
	HP--;
	if (HP <= 0) {
		//オプションとチェンジする処理をここに
	}
}
