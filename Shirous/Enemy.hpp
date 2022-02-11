#pragma once

# include <Siv3D.hpp>
# include"Unit.hpp"
class Enemy :
	public Unit
{


private:

	double mySpeed = 100.0;


public:

	Enemy();
	~Enemy();

	void Update(double deltaTime, bool& gameover);

	void Draw();


};
