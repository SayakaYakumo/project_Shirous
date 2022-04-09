#include "stdafx.h"
#include "Item.hpp"

int Item::item_high_speed = 720;
int Item::item_middle_speed = 540;
int Item::item_low_speed = 240;

Item::Item(Vec2 v, ItemType t)
	:area(RectF(v, 50)), type(t), mode(Mode_Chase), speed(item_high_speed)
{
	target = RandomVec2(Circle(v, 150));

	//ここでタイプごとに名前指定
	switch (t)
	{
	case Bomb_I:
		name = U"Bomb";
		break;
	case Life_I:
		name = U"Life";
		break;
	case Feed_I:
		name = U"Feed";
		break;
	case Score_I:
		name = U"Score";
		break;
	case Power_I:
		name = U"Power";
		break;
	default:
		break;
	}
}

void Item::Update(double deltaTime, Vec2 playerPos) {
	if (appear_time > appear_count) {
		appear_count += deltaTime;
	}
	else if (playerPos.x > collection_line) {
		mode = Mode_Chase;
		target = playerPos;
		speed = item_high_speed;
	}
	else if (Circle(playerPos, 256).intersects(area)) {
		mode = Mode_Chase;
		target = playerPos;
		speed = item_middle_speed;
	}
	else {
		mode = Mode_Left;
		speed = item_low_speed;
	}
	switch (mode)
	{
	case Item::Mode_Stop:

		break;
	case Item::Mode_Left:
		area.moveBy(-speed * deltaTime, 0);
		break;
	case Item::Mode_Chase:
		Vec2 v = target - area.center();
		v.normalize();
		area.moveBy(v * speed * deltaTime);
		break;
	default:
		break;
	}

	//画面上下に出ないよう調整
	area.pos.y =  Clamp(area.pos.y, 0.0, 1280 - area.h);
}

void Item::Draw() const {
	String texture_name = U"item_" + name;

	area(TextureAsset(texture_name)).draw();
}
