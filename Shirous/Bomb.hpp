#pragma once

class Bomb {
protected:
	//発動タイマー
	double bombTime = 0;

	//発動する長さ
	double bombSustainTime = 2.0;

	//一回のヒットでのダメージ
	int power = 2;

	//発動しているかどうか
	bool bombActive = false;

	//(プレイヤーに合わせて動かす場合のための)基準座標
	Vec2 basePos{ 0,0 };

	//使用可能回数
	int bombNum = 10;

	//一回の発動でのヒット数
	int bombHitNum = 20;

	//ここまでの判定数
	int hitCount = 0;

	//ヒット確認状態かどうか
	bool hit = false;

	//エフェクト
	Effect effect;

public:

	Bomb();

	~Bomb();

	//発動時にはこれを呼び出す
	void Start();

	//デルタ時間とプレイヤー座標を受け取る
	void Update(double deltaTime, Vec2 playerPos);

	//当たり判定などのエリアを設定する
	virtual void setArea();

	//重なり判定(敵用)
	virtual bool intercects(Rect rect);

	//重なり判定(敵弾用)
	virtual bool intercects(Circle circle);

	//発動中かどうかを得る
	bool isActive() const;

	//ボムの残り数を得る
	int getBombNum() const;

	//エフェクトを追加する
	virtual void addEffect();

	//描画
	virtual void Draw()const;

	//一ヒットあたりのダメージを調べる
	int get_power() { return power; }

	//ボム取得時
	void chatch_bomb() { bombNum++; }
};
