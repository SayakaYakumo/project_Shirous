#include "Enemy.hpp"





Enemy::Enemy(String name_,int x,int y,int move,int shot_pattern_,Array<Rect> rects)
{
	rect = Rect(x, y, 100, 100);

	name = name_;

	speed = 200;

	move_pattern = move;

	shot_pattern = shot_pattern_;

	make_bullet_point = Vec2(x,y);

	make_bullet_point_adjust_x = 20;
	make_bullet_point_adjust_y = 30;

	for (size_t i = 0; i < rects.size(); i++) {
		hit_rect.push_back(Hit_Rect(rects[i]));
	}
	//アイテムを出すテストをしたいので入れてるやつ
	drop_item.push_back(Drop_Item(Bomb_I, 3));
	drop_item.push_back(Drop_Item(Life_I, 2));
}

Enemy::~Enemy()
{


}

void Enemy::Update(double deltaTime)
{
	move_count += deltaTime;
	shot_count += deltaTime;

	move( deltaTime);//移動

	for (size_t i = 0; i < hit_rect.size(); i++) {//当たり判定の四角形たちを調整
		hit_rect[i].update(rect.x,rect.y);
	}

	make_bullet_point.x = rect.x + make_bullet_point_adjust_x;//弾を出す位置を調整
	make_bullet_point.y = rect.y + make_bullet_point_adjust_y;//弾を出す位置を調整

	shot();//ショット
}

void Enemy::Draw()const
{

	String texture_name = U"enemy_" + name;

	TextureAsset(texture_name).draw(rect.x, rect.y);

	Rect rect_d(rect.x,rect.y,5,5);

	rect_d.draw();

}

void Enemy::DrawFrame() const{

	for (size_t i = 0; i < hit_rect.size(); i++) {
		hit_rect[i].draw();
	}
}

void Enemy::move(double deltaTime) {

	move_0(deltaTime);
	
	switch (move_pattern)
	{
	case 0:
		move_0(deltaTime);
		break;
	case 1:
		move_1(deltaTime);
		break;
	case 2:
		move_2(deltaTime);
		break;
	case 3:
		move_3(deltaTime);
		break;
	case 4:
		move_4(deltaTime);
		break;
	case 5:
		move_5(deltaTime);
		break;
	case 6:
		move_6(deltaTime);
		break;
	default:
		break;
	}
}


void Enemy::move_0(double deltaTime) {
	rect.x -= deltaTime * speed;

	//Print<<U"speed::"<< speed;
	//Print << U"x" << rect.x;
	//Print << U"-------";
}

void Enemy::move_1(double deltaTime) {
	rect.x -= deltaTime * speed;
}

void Enemy::move_2(double deltaTime) {
	rect.x -= deltaTime * speed;
}

void Enemy::move_3(double deltaTime) {
	rect.x -= deltaTime * speed;
}

void Enemy::move_4(double deltaTime) {
	rect.x -= deltaTime * speed;
}

void Enemy::move_5(double deltaTime) {
	rect.x -= deltaTime * speed;
}

void Enemy::move_6(double deltaTime) {
	rect.x -= deltaTime * speed;
}


void Enemy::shot() {

	switch (shot_pattern)
	{
	case 0:
		shot_0();
		break;
	case 1:
		shot_1();
		break;
	case 2:
		shot_2();
		break;
	case 3:
		shot_3();
		break;
	case 4:
		shot_4();
		break;
	case 5:
		shot_5();
		break;
	case 6:
		shot_6();
		break;
	default:
		break;
	}
}

void Enemy::shot_0() {

	if (shot_count > 3) {
		make_bullet_flag = 0;
		
		shot_count = 0;
	}
}

void Enemy::shot_1() {

}

void Enemy::shot_2() {

}

void Enemy::shot_3() {

}

void Enemy::shot_4() {

}

void Enemy::shot_5() {

}

void Enemy::shot_6() {

}

Array<Item> Enemy::get_items() {
	Array<Item> items;
	for (size_t i = 0; i < drop_item.size(); i++) {

		for (int j = 0; j < drop_item[i].get_amount(); j++) {
			Item item_new = Item(rect.center(), drop_item[i].get_item());
			items.push_back(item_new);
		}
	}
	return items;
}
