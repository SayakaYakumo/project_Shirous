#pragma once
#include "Common.hpp"
#include "Enemy.hpp"
#include "Player.hpp"
#include "PlayerBullet.hpp"
#include "EnemyBullet.hpp"
#include"EmergeEnemy.hpp"

class Game : public App::Scene
{
public:

	Game(const InitData& init);


	//Update
	void update() override;

	void update_first();
	void update_main();
	void update_pose();
	void update_gameover();

	//Draw
	void draw() const override;

	void draw_main() const;
	void draw_pose() const;
	void draw_gameover() const;

	//ショット生成
	void make_player_bullet();
	void make_enemy_bullet(int,int);

	//ショットの移動関係
	void GameShotUpdate(const double _time);
	//移動関係
	void GameMoveUpdate(const double _time);
	
	//ショットのヒット判定
	void GameHitUpdate();

	//敵などを消す
	void GameEraseUpdate();

	

	//一番近い敵を取得

	//Enemy NearEnemy();

	double dist(Vec2 _SetPos, Vec2 _TargetPos);
	double dist(double x1, double y1, double x2, double y2);


	void draw_main_back()const;
	void draw_player()const;
	void draw_enemy()const;
	void draw_bullet()const;

	//ステージデータ読み込み
	//Game/First/Update_First

	//Stage1
	void stage_1_load();

	//Stage2
	void stage_2_load();

	//Stage3
	void stage_3_load();

	//Stage4
	void stage_4_load();

	//Stage5
	void stage_5_load();

	//Stage6
	void stage_6_load();


private:

	//「ゲーム」の中のシーン
	//読み込み・・・０
	//メイン・・・１
	//ポーズ・・・２
	//ゲームオーバー・・・３
	int game_scene = 0;

	//ステージスクロールスピード
	double stage_speed = 300;

	//スクロール
	double scroll = 0;

	//現在のステージ番号
	int stage_number = 1;

	//ステージ経過時間
	double stage_time = 0;



	// 大きさ 60 のフォントを用意
	Font font;
	Font gameoverfont;

	

	Effect effect;


	//プレイヤー
	Player gamePlayer;

	Array<PlayerBullet> gamePlayerBullet;

	//敵
	Array<Enemy> gameEnemys;

	Array<EnemyBullet> gameEnemyBullet;

	//敵出現データ
	Array<EmergeEnemy> emergeEnemys;

	// 自機ショットのクールタイム（秒）
	double playerShotCoolTime = 0.5;
	// 自機ショットのクールタイムタイマー
	double playerShotTimer = 0.0;

	// 敵ショットのクールタイム（秒）
	double enemyShotCoolTime = 0.90;
	// 敵ショットのクールタイムタイマー
	double enemyShotTimer = 0.0;


	// ハイスコア
	int32 highScore = 0;
	// 現在のスコア
	int32 score = 0;
};
