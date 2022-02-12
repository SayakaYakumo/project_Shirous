#pragma once
# include <Siv3D.hpp>

class Game_Data {

public:

	int get_high_score() { return _high_score; }

	void set_high_score(int v) { _high_score; }

private:

	int _high_score;

	
};
