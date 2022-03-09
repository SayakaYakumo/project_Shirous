#include "Player.hpp"

Player::Player()
{
	start();//初期位置

	name = U"シラス";

	speed = mySpeed;

}

Player::~Player()
{

}
void Player::Update(double deltaTime)
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

	if (rect.x<0) {
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
	shot_cool_time -= deltaTime;

}

void Player::Draw()const
{
	// 自機の描画
	//texture.mirrored().resized(80).drawAt(pos);

	String texture_name = U"player_" + name;

	TextureAsset(texture_name).draw(rect.x-10, rect.y-20);



}


void Player::DrawFrame()const {
	rect.drawFrame();
}



void Player::start() {
	rect.x = 300;
	rect.y = 300;
	rect.w = 160;
	rect.h = 30;

	shot_cool_time = 0;
}

Vec2 Player::getPos() {
	return { rect.x,rect.y };
}
