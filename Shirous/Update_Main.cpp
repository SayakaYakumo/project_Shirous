#include"Game.hpp"

void Game::update_main() {

	const double deltaTime = Scene::DeltaTime();

	//ステージ時間に追加
	stage_time += deltaTime;

	

	// 敵の発生
	for (size_t i = 0; i < emergeEnemys.size(); i++) {
		if (emergeEnemys[i].get_time() > stage_time) {//時間を超えた
			if (emergeEnemys[i].get_done() == 0) {//まだ使われていない
				emergeEnemys[i].set_done();//使われたフラグをたてる

				String name = emergeEnemys[i].get_name();
				int x = emergeEnemys[i].get_x();
				int y = emergeEnemys[i].get_y();
				int move = emergeEnemys[i].get_move();
				int shot_pattern = emergeEnemys[i].get_shot_pattern();

				gameEnemys.push_back(Enemy(name,x,y,move,shot_pattern));//敵を生成する！！
			}
		}
	}

    //移動
	GameMoveUpdate(deltaTime);

	
	//Shot周り
	GameShotUpdate(deltaTime);


	//攻撃のヒット判定
	GameHitUpdate();

	//敵などを消す
	GameEraseUpdate();



}


void Game::GameMoveUpdate(const double _time)
{
	//自機の移動と描画
	gamePlayer.Update(_time);

	//敵の移動と描画
	for (auto& enemy : gameEnemys)
	{
		enemy.Update(_time);
	}
}

void Game::GameShotUpdate(const double _time)
{

	// 敵ショットの発射
	for (size_t i = 0; i < gameEnemys.size(); i++) {

		int v = gameEnemys[i].get_bullet_flag();//弾発射のフラグを取得
		if (v != -1) {
			make_enemy_bullet(i,v);//弾生成
			gameEnemys[i].reset_bullet_flag();//弾発射のフラグを消す
		}
	}

	// 敵ショットの移動
	for (auto& enemyBullet : gameEnemyBullet)
	{
		enemyBullet.Update(_time);

	}

	// 画面外の敵ショットの削除
	gameEnemyBullet.remove_if([&](EnemyBullet e)
		{
			if (e.get_circle().x > 2000 || e.get_circle().x < -100 || e.get_circle().y>1100 || e.get_circle().y < -100) {

				return true;
			}
			else {
				return false;
			}

		});

	//自機ショット

	//自機ショット生成
	if (KeyZ.pressed()) {
		if (gamePlayer.get_cool_time() < 0) {//クールタイム終了
			make_player_bullet();//弾生成
		}
	}

	for (auto& playerBullet : gamePlayerBullet)
	{
		playerBullet.Update(_time);
	}

	// 画面外の自機ショットの削除
	gamePlayerBullet.remove_if([&](PlayerBullet p)
		{
			if (p.get_circle().x>2000|| p.get_circle().x < -100|| p.get_circle().y>1100|| p.get_circle().y < -100) {

				return true;
			}
			else {
				return false;
			}

		});
}


void Game::GameHitUpdate() {

	// 敵 vs 自機ショット
	
	size_t b_size = gamePlayerBullet.size();

	Array<int> b_check;

	for (size_t i = 0; i < b_size; i++) {
		b_check.push_back(0);
	}


	for (size_t i = 0; i < gameEnemys.size(); i++) {

		for (size_t s = 0; s < gameEnemys[i].get_hit_rect_size(); s++) {

			Rect e_rect = gameEnemys[i].get_hit_rect(s);

			for (size_t j = 0; j < gamePlayerBullet.size(); j++) {

				

					Circle b_circle = gamePlayerBullet[j].get_circle();

					if (b_circle.intersects(e_rect)) {

						gameEnemys[i].damage(gamePlayerBullet[j].get_power());
						b_check[j] = 1;
					}

			}
		}
	}


	int b_adjust = 0;

	for (size_t i = 0; i < b_size; i++) {

		if (b_check[i] == 1) {

			
			gamePlayerBullet.remove_at(i - b_adjust);

			b_adjust++;

		}

	}


	//自機vs敵

	for (size_t i = 0; i < gameEnemys.size(); i++) {
		for (size_t e = 0; e < gameEnemys[i].get_hit_rect_size(); e++) {

			if (gameEnemys[i].get_hit_rect(e).intersects(gamePlayer.get_rect())){//当たった時

			}
		}
	}

	//自機と敵弾
	gameEnemyBullet.remove_if([&](EnemyBullet e)
		{
			if (e.get_circle().intersects(gamePlayer.get_rect())) {//敵の弾が当たった

				return true;
			}
			else {
				return false;
			}

		});

}



void Game::GameEraseUpdate() {

	//体力のなくなった敵を消す
	gameEnemys.remove_if([&](Enemy e)
		{
			if (e.get_hp()<=0) {

				return true;
			}
			else {
				return false;
			}

		});

}

//参考にしたプログラムのホーミング弾があったときの名残、使うかもしれないので一応残しておく
/*
Enemy Game::NearEnemy()
{
	/*
	Enemy set;
	double checkDis = 1000;

	for (auto& enemy : gameEnemys)
	{

		auto _dis = dist(Vec2(gamePlayer.rect.x,gamePlayer.rect.y), Vec2(enemy.rect.x,enemy.rect.y));

		if (_dis < checkDis)
		{
			checkDis = _dis;
			set = enemy;
		}
	}
	return set;
}
*/

double Game::dist(Vec2 _SetPos, Vec2 _TargetPos)
{

	return dist(_SetPos.x, _SetPos.y, _TargetPos.x, _TargetPos.y);
}

double Game::dist(double x1, double y1, double x2, double y2)
{

	double dx, dy;

	dx = x2 - x1;
	dy = y2 - y1;

	return Math::Sqrt(dx * dx + dy * dy);

}
