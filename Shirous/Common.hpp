#pragma once
# include <Siv3D.hpp>

// シーンの名前
enum class State
{
	Title,
	Menu,
	Game,
};

// 共有するデータ
struct GameData
{
	// スコア
	int score = 0;
};

using App = SceneManager<State, GameData>;
