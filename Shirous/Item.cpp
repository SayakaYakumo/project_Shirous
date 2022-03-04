#include "stdafx.h"
#include "Item.hpp"

Item::Item(Vec2 v, ItemType t)
	:area(RectF(v, 50)), type(t), mode(Mode_Chase), speed(item_high_speed)
{
	target = RandomVec2(Circle(v, 150));

	//ここでタイプごとに名前指定
	switch (t)
	{
	case Bomb_I:
		name = U"赤";
		break;
	case Life_I:
		name = U"青";
		break;
	case Feed_I:
		break;
	case Score_I:
		break;
	case Power_I:
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
