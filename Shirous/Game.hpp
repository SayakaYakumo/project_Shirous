#pragma once
#include "Common.hpp"
#include "Enemy.hpp"
#include "Player.hpp"
#include "PlayerBullet.hpp"
#include "EnemyBullet.hpp"
#include"EmergeEnemy.hpp"
#include"Back_Tile.hpp"
#include"Enemy_Data.hpp"
#include"Save_Data.hpp"
#include"Stage_Data.hpp"

class Game 
{
public:

	


	//Game
	void ini();
	void update();
	void draw();

	//Debug
	void load_debug();

	//Chnage_Scene
	void change_scene(int);
	void update_change_scene();
	void draw_change_scene();


	//Game
	void update_title();
	void update_menu();
	void update_play();

	
	void draw_title();
	void draw_menu();
	void draw_play();

	//play
	int play_scene = 0;

	void play_load(int);//update_change_sceneで呼ばれます

	void update_main();
	void update_pose();
	void update_gameover();

	void draw_main() const;
	void draw_pose() const;
	void draw_gameover() const;



	//Debug(Menu)
	void update_debug_menu();
	void draw_debug_menu();
	
	void update_debug_menu_stage_select();
	void update_debug_menu_mode_select();


	void update_edit_player();
	void draw_edit_player();
	void update_edit_option();
	void draw_edit_option();
	void update_edit_enemy();
	void draw_edit_enemy();

	void draw_debug_menu_stage_select();
	void draw_debug_menu_mode_select();
	
	void update_edit_input_number();
	void draw_edit_input_number();


	//Edit
	void update_edit();
	void draw_edit();

	void update_edit_ini();
	void update_edit_main();


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

	//Playシーンの描画

	void draw_main_back()const;
	void draw_player()const;
	void draw_enemy()const;
	void draw_bullet()const;
	void draw_ui()const;

	//ステージデータ読み込み
	//Game/First/Update_First

	//Stage0
	void stage_0_load();


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

	//Stage7
	void stage_7_load();

	//Stage8
	void stage_8_load();

	//Stage9
	void stage_9_load();

	Array<Back_Tile> back_tile;

private:

	//デバッグモード
	int debug = 1;

	//プレイ中のデバッグモード
	int debug_play = 1;

	//「ゲーム」の中のシーン
	//読み込み・・・０
	//メイン・・・１
	//ポーズ・・・２
	//ゲームオーバー・・・３
	int game_scene = 0;


	//チェンジシーン
	int change_scene_count = 0;
	int change_scene_number = 0;
	double change_scene_screen_fade = 0;
	//0が普通のもの・(1は長め)
	int change_scene_type = 0;

	//メニュー

	//メニュー（デバッグ）
	int debug_menu_scene = 0;
	
	int debug_stage_number = 0;

	int debug_stage_select = 0;

	int debug_cur_cover_x = -1;
	int debug_cur_cover_y = -1;

	int debug_2_cur_cover = -1;


	
	//エディタ
	int edit_scene = 0;
	int edit_scroll = 0;
	int edit_display = 0;
	int edit_select_item = 0;
	int edit_select_tile_kind = 0;
	int edit_information = 0;

	int edit_bukket = 0;
	int edit_bukket_start_x = 0;
	int edit_bukket_start_y = 0;

	String  edit_plus_enemy_name ;
	

	double edit_saved_display_fade = 0;
	int edit_saved = 0;

	int edit_enemy_scene = 0;
	int edit_enemy_index = 0;

	int edit_enemy_page = 0;
	int edit_enemy_information = 1;
	int edit_enemy_information_scene = 0;
	int edit_enemy_cur_cover = -1;
	int edit_enemy_cur_cover_2 = -1;
	int edit_enemy_cur_cover_3 = -1;

	String edit_input_v;
	int edit_input_over = -1;
	int edit_input_point = 0;
	int edit_input_end = 0;

	String edit_enemy_name;
	String edit_enemy_name_editing;
	int edit_enemy_name_cover = 0;

	int edit_enemy_page_x = 0;
	int edit_enemy_page_y = 0;

	int edit_enemy_display = 1;

	int edit_enemy_make_rect_scene = 0;
	int edit_enemy_make_rect_x = 0;
	int edit_enemy_make_rect_y = 0;
	Rect edit_enemy_rect;

	int edit_enemy_information_cover = -1;
	

	int edit_enemy_select_item = 1;
	double edit_enemy_saved_display_fade = 0;

	Circle cir;//デバッグ用

	//セーブデータ
	Save_Data save_data;

	Stage_Data stage_data;

	//ステージスクロールスピード
	double stage_speed = 200;

	//ステージワイド
	int stage_wide = 1;

	//スクロール
	double stage_scroll = 0;

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

	//サカナデータ
	Array<Enemy_Data> enemy_data;

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
