#pragma once
#include "Bomb.hpp"

class Bomb_Laser : public Bomb
{
private:

	Array<RectF> hitAreas;

	double deg_up = 30_deg;
	double deg_down = -30_deg;
	double size_minus = 0;

	int effect_count = 0;
	const int effect_num = 60;

public:
	Bomb_Laser();
	~Bomb_Laser();

	virtual void setArea();

	virtual bool intercects(Rect rect);

	virtual bool intercects(Circle circle);
	
	virtual void addEffect();

	virtual void Draw()const;
};
