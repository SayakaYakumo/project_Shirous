#include "Enemy.hpp"
#include"Player.hpp"





Enemy::Enemy(String name_,int x,int y,int hp_,int act_,int move_,int shot_pattern_,Array<Rect> rects)
{
	name = name_;
	rect = Rect(x, y, 100, 100);
	String texture_name = U"enemy_" + name_;
	rect.w = TextureAsset(texture_name).width() * 0.9;
	rect.h = TextureAsset(texture_name).height() * 0.9;
	speed = 120;

	hp = hp_;
	act_pattern = act_;
	move_pattern = move_;

	shot_pattern = shot_pattern_;

	make_bullet_point = Vec2(x,y);

	make_bullet_point_adjust_x = 20;
	make_bullet_point_adjust_y = 30;

	for (size_t i = 0; i < rects.size(); i++) {
		hit_rect.push_back(Hit_Rect(rects[i]));
	}
	//アイテムを出すテストをしたいので入れてるやつ
	drop_item.push_back(Drop_Item(Bomb_I, 1));
	drop_item.push_back(Drop_Item(Life_I, 1));
	drop_item.push_back(Drop_Item(Score_I, 3));
	drop_item.push_back(Drop_Item(Feed_I, 10));
	drop_item.push_back(Drop_Item(Power_I, 2));
}

Enemy::~Enemy()
{


}

void Enemy::Update(double deltaTime)
{
	move_count += deltaTime;
	shot_count += deltaTime;

	if (act_pattern == -1) {
		move(deltaTime);//移動
        shot();//ショット
	}
	else {
		act(deltaTime);//行動
	}



	for (size_t i = 0; i < hit_rect.size(); i++) {//当たり判定の四角形たちを調整
		hit_rect[i].update(rect.x,rect.y);
	}

	make_bullet_point.x = rect.x + make_bullet_point_adjust_x;//弾を出す位置を調整
	make_bullet_point.y = rect.y + make_bullet_point_adjust_y;//弾を出す位置を調整

	
}

void Enemy::Update(double deltaTime, RectF player_rect)
{
	move_count += deltaTime;
	shot_count += deltaTime;
	read_player_pos(player_rect);
	if (act_pattern == -1) {
		move(deltaTime);//移動
		shot();//ショット
	}
	else {
		act(deltaTime);//行動
	}



	for (size_t i = 0; i < hit_rect.size(); i++) {//当たり判定の四角形たちを調整
		hit_rect[i].update(rect.x, rect.y);
	}

	make_bullet_point.x = rect.x + make_bullet_point_adjust_x;//弾を出す位置を調整
	make_bullet_point.y = rect.y + make_bullet_point_adjust_y;//弾を出す位置を調整


}

void Enemy::Draw()const
{

	String texture_name = U"enemy_" + name;

	TextureAsset(texture_name).draw(rect.x, rect.y);
}

void Enemy::DrawFrame() const{

	Rect rect_d(rect.x, rect.y, 5, 5);

	rect_d.draw();

	for (size_t i = 0; i < hit_rect.size(); i++) {
		hit_rect[i].draw();
	}
}

void Enemy::act(double deltaTime) {



	switch (act_pattern)
	{
	case 0:
		act_0(deltaTime);
		break;
	case 1:
		act_1(deltaTime);
		break;
	case 2:
		act_2(deltaTime);
		break;
	case 3:
		act_3(deltaTime);
		break;
	case 4:
		act_4(deltaTime);
		break;
	case 5:
		act_5(deltaTime);
		break;
	case 6:
		act_6(deltaTime);
		break;
	default:
		break;
	}
}

void  Enemy::act_0(double deltaTime) {

}

void  Enemy::act_1(double deltaTime) {

}

void  Enemy::act_2(double deltaTime) {

}

void  Enemy::act_3(double deltaTime) {
	////Playerの位置と敵の位置を引き、その位置ベクトルを敵の

	Vec2 dir = Enemy::PlayerRect.movedBy(250, 0).center() - Vec2{ rect.x,rect.center().y };
	rect.x += double(dir.normalized().x * 6);
	rect.y += double(dir.normalized().y * 6);
}

void Enemy::act_4(double deltaTime) {

}

void Enemy::act_5(double deltaTime) {

}

void Enemy::act_6(double deltaTime) {

}

void Enemy::read_player_pos(RectF PlayerRect_)
{
	Enemy::PlayerRect = PlayerRect_;
}
void Enemy::move(double deltaTime) {

	
	
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


void Enemy::move_0(double deltaTime) {//まっすぐ
	rect.x -= deltaTime * speed;

	//Print<<U"speed::"<< speed;
	//Print << U"x" << rect.x;
	//Print << U"-------";
}

void Enemy::move_1(double deltaTime) {//sin波
	rect.x -= deltaTime * speed;
	count_2 += deltaTime;

	rect.y += sin(3.14 * 2 / 120 * (count_2*20)) * 5;
	
}

void Enemy::move_2(double deltaTime) {//真ん中あたりまで来て、しばらくするともどっていく
	count += deltaTime;
	if (count < 10)
	{
		rect.x -= deltaTime * speed / (1 + count);
	}
	if (count > 10)
	{
		rect.x += deltaTime * speed;
	}
	
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

void Enemy::shot_0() {//通常弾

	if (shot_count > 1) {
		make_bullet_flag = 0;
		
		shot_count = 0;
	}
}

void Enemy::shot_1() {//三連射

	if (shot_scene==0) {

		if (shot_count > 0.2) {
			make_bullet_flag = 0;

			shot_count = 0;
			shot_scene++;
		}
	}
	else if (shot_scene == 1) {

		if (shot_count > 0.2) {
			make_bullet_flag = 0;

			shot_count = 0;
			shot_scene++;
		}

		
	}
	else if (shot_scene == 2) {

		if (shot_count > 0.2) {
			make_bullet_flag = 0;

			shot_count = 0;
			shot_scene++;
		}


	}
	else if (shot_scene == 3) {

		if (shot_count > 2) {

			shot_count = 0;
			shot_scene=0;
		}
	}

	
}

void Enemy::shot_2() {

	if (shot_count > 1) {
		make_bullet_flag = 1;

		shot_count = 0;
	}
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
