#include "Player_Fish.hpp"

Fish::Fish()
{
	first();

	name = U"シラス";

	speed = mySpeed;

}
Fish::Fish(RectF r)
{
	first(r);

	name = U"シラス";

	speed = mySpeed;

}
Fish::Fish(String n)
{
	first();

	name = n;

	speed = mySpeed;

}


Fish::~Fish()
{

}
void Fish::myUpdate(double deltaTime)
{
	int naname = 0;

	if (KeyUp.pressed() || KeyDown.pressed()) {
		if (KeyLeft.pressed() || KeyRight.pressed()) {
			naname = 1;
		}
	}

	double now_speed = speed * deltaTime;

	if (naname == 1) {//斜め移動中
		now_speed *= 0.7;
	}

	if (KeyShift.pressed()) {//減速
		now_speed *= 0.5;
	}


	if (KeyUp.pressed()) {//上
		rect.y -= now_speed;
	}
	else if (KeyDown.pressed()) {//下
		rect.y += now_speed;
	}

	if (KeyLeft.pressed()) {//左
		rect.x -= now_speed;
	}
	else if (KeyRight.pressed()) {//右
		rect.x += now_speed;
	}

	//画面の移動制限

	if (rect.x < 0) {
		rect.x = 0;
	}
	else if (rect.x + rect.w > 1920) {
		rect.x = 1920 - rect.w;
	}

	if (rect.y < 0) {
		rect.y = 0;
	}
	else if (rect.y + rect.h > 1080) {
		rect.y = 1080 - rect.h;
	}

	//ショットのクールタイム
	shot_timer += deltaTime;

}

void Fish::opUpdate(int i, RectF player ,double deltaTime)
{
	option_pos_timer += deltaTime;
	if (option_pos_timer > 20*Math::Pi)option_pos_timer -= 20*Math::Pi;
	Vec2 moved = Vec2(-50*i, 15*i*Math::Sin(option_pos_timer/i));

	option_speed += Vec2(player.x - rect.x + moved.x, player.y - rect.y + moved.y) / 5;
	if (option_speed.length() > mySpeed)option_speed = option_speed / option_speed.length() * mySpeed;
	if (option_slow_timer > 0.1)
	{
		option_speed /= 2.0;
		option_slow_timer -= 0.1;
	}

	rect.x += option_speed.x * deltaTime;
	rect.y += option_speed.y * deltaTime;

	//画面の移動制限

	if (rect.x < 0) {
		rect.x = 0;
	}
	else if (rect.x + rect.w > 1920) {
		rect.x = 1920 - rect.w;
	}

	if (rect.y < 0) {
		rect.y = 0;
	}
	else if (rect.y + rect.h > 1080) {
		rect.y = 1080 - rect.h;
	}

	//ショットのクールタイム
	shot_timer += deltaTime/2;

	//移動速度減衰のクールタイム
	option_slow_timer += deltaTime;

}

void Fish::Draw()const
{
	// 自機の描画
	//texture.mirrored().resized(80).drawAt(pos);

	String texture_name = U"player_" + name;

	TextureAsset(texture_name).draw(rect.x - 10, rect.y - 20);



}


void Fish::DrawFrame()const {
	rect.drawFrame();
}



void Fish::first() {
	rect.x = 300;
	rect.y = 300;
	rect.w = 160;
	rect.h = 30;

}
void Fish::first(RectF r) {
	rect = r;

}
