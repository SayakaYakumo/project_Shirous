#pragma once

class PlayerBullet 
{
private:

	double speed = 0;

	int move = 0;

	Circle circle;

	String color;

	String shape;

	bool pen = false;//貫通弾。ダメージをdouble型にして一秒あたりのダメージにする。敵が大きいほどダメージを稼げる

	String size;//circle.rとは異なる

	double angle = 0;

	double power = 1;

public:

	

	PlayerBullet(int x,int y,int r,int speed_,int move_,double angle_,String shape_,String color_,String size_, int pow_ = 1) {
		circle = Circle(x, y, r);
		speed = speed_;
		move = move_;
		angle = angle_;
		shape = shape_;
		pen = false;
		color = color_;
		size = size_;
	}
	PlayerBullet(int x, int y, int r, int speed_, int move_, double angle_, String shape_, String color_, String size_, bool pen_, double power_) {
		circle = Circle(x, y, r);
		speed = speed_;
		move = move_;
		angle = angle_;
		shape = shape_;
		pen = pen_;
		power = power_;
		color = color_;
		size = size_;
	}
	~PlayerBullet() {

	}




	void Update(double deltaTime);

	void Draw()const;

	void Draw_Frame()const;

	Circle get_circle() { return circle; }

	double get_power() { return power; }

	bool get_pen() { return pen; }
};
