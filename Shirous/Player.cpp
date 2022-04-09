#include "Player.hpp"
#include "PlayerEffect.hpp"

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

	damage_timer -= deltaTime;
	if (damage_timer < 0) damage_timer = 0;

	Spawn2(deltaTime);

}

void Player::Draw()const
{
	// 自機の描画

	for (int i = 0; i < fish.size(); i++)
	{
		if (i == 0 && damage_timer > 0) {
			double a = 0.5 * (Cos(damage_timer * 2.0 * Math::Pi) + 1.0) / 2.0;
			fish[0].Draw(a);
		}
		else fish[i].Draw();
	}
	effect.update();
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

		if (useFeed >= effect_count * 10) {
			effect_count++;
			effect.add<CircleEffect>(get_rect().center(), 300);
		}
	}

	if (KeyC.up() || (KeyC.pressed() && useFeed == feed)) {

		if (spawn_cool_time <= 0) {
			effect_count = 0;
			effect.clear();

			if (useFeed >= 10) effect.add<CircleEffect>(get_rect().center(), 1500, false);
			else effect.add<SmokeEffect>(get_rect().center());
		}

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
	if (damage_timer > 0) return;
	HP--;
	damage_timer = damage_cool_time;
	effect.add<DamageEffect>(get_rect().center());
	if (HP <= 0) {
		//オプションとチェンジする処理をここに
	}
}
