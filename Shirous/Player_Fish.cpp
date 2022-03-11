#include "Player_Fish.hpp"

Fish::Fish()
{
	name = U"シラス";

	first();

}
Fish::Fish(RectF r)
{
	name = U"シラス";

	first(name, r);

}
Fish::Fish(String n, RectF r)
{
	name = n;

	first(name, r);

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
	//自機の移動
	opMove(i, player, deltaTime);

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
	shot_timer += deltaTime/4;

	//移動速度減衰のクールタイム
	option_slow_timer += deltaTime;

}

void Fish::opMove(int i, RectF player, double deltaTime)
{
	if (name == U"シラス")
	{
		option_pos_timer += deltaTime;
		if (option_pos_timer > 20 * Math::Pi)option_pos_timer -= 20 * Math::Pi;

		Vec2 moved = Vec2(-50 * i, 15 * i * Math::Sin(option_pos_timer / i));
		option_speed += Vec2(player.x - rect.x + moved.x, player.y - rect.y + moved.y) / 5;
		if (option_speed.length() > mySpeed)option_speed = option_speed / option_speed.length() * mySpeed;
		if (option_slow_timer > 0.1)
		{
			option_speed /= 2.0;
			option_slow_timer -= 0.1;
		}

		rect.x += option_speed.x * deltaTime;
		rect.y += option_speed.y * deltaTime;
	}
	if (name == U"アンコウ")
	{
		option_pos_timer += deltaTime;
		if (option_pos_timer > 20 * Math::Pi)option_pos_timer -= 20 * Math::Pi;

		Vec2 moved = Vec2(-50 * i, -player.y + 900 + 15 * i * Math::Sin(option_pos_timer / i));
		option_speed += Vec2(player.x - rect.x + moved.x, player.y - rect.y + moved.y) / 5;
		if (option_speed.length() > mySpeed)option_speed = option_speed / option_speed.length() * mySpeed;
		if (option_slow_timer > 0.1)
		{
			option_speed /= 2.0;
			option_slow_timer -= 0.1;
		}

		double slowness = 1;
		if (rect.y < 800) slowness = 2;
		rect.x += option_speed.x * deltaTime / slowness;
		rect.y += option_speed.y * deltaTime / slowness;
	}
	if (name == U"ハリセンボン")
	{
		option_pos_timer += deltaTime;
		if (option_pos_timer > 20 * Math::Pi)option_pos_timer -= 20 * Math::Pi;

		Vec2 moved = Vec2(-50 * i, 15 * i * Math::Sin(option_pos_timer / i));
		option_speed += Vec2(player.x - rect.x + moved.x, player.y - rect.y + moved.y) / 5;
		if (option_speed.length() > mySpeed)option_speed = option_speed / option_speed.length() * mySpeed;
		if (option_slow_timer > 0.1)
		{
			option_speed /= 2.0;
			option_slow_timer -= 0.1;
		}

		double slowness = 1;
		rect.x += option_speed.x * deltaTime / slowness;
		rect.y += option_speed.y * deltaTime / slowness;
	}
}

void Fish::Draw()const
{
	// 自機の描画
	//texture.mirrored().resized(80).drawAt(pos);

	String texture_name = U"player_" + name;

	TextureAsset(texture_name).draw(rect.x - rect.w/18, rect.y - rect.h / 18);



}


void Fish::DrawFrame()const {
	rect.drawFrame();
}



void Fish::first() {
	rect.x = 300;
	rect.y = 300;
	rect.w = Texture(U"data/image/fish/player/シラス.png").width() * 0.9;
	rect.h = Texture(U"data/image/fish/player/シラス.png").height() * 0.9;

	speed = mySpeed;
}
void Fish::first(RectF r) {
	rect = r;

	speed = mySpeed;

}
void Fish::first(String name, RectF r) {
	String texture_name = U"player_" + name;

	rect.x = r.x;
	rect.y = r.y;
	rect.w = TextureAsset(texture_name).width()*0.9;
	rect.h = TextureAsset(texture_name).height()*0.9;

	speed = mySpeed;
}
