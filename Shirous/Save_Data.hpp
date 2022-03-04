#pragma once
# include <Siv3D.hpp>

class Save_Data {

public:

	int get_high_score(int v) { return _high_score[v]; }

	int get_best_score() {
		int max = 0;
		for (size_t i = 0; i < _high_score.size(); i++) {
			if (max < _high_score[i]) {
				max = _high_score[i];
			}
		}

		return max;

	}

	void set_high_score(int index, int v) { _high_score[index] = v;; }

	// シリアライズに対応させるためのメンバ関数を定義する
	template <class Archive>
	void SIV3D_SERIALIZE(Archive& archive)
	{
		archive(_high_score);
	}


private:

	Array<int> _high_score;

	
};
