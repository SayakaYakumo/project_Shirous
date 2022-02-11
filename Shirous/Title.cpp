#include "Title.hpp"

Title::Title(const InitData& init)
	: IScene{ init }
{

}

void Title::update()
{
	if (MouseL.down())
	{
		// メニューに遷移
		changeScene(State::Menu);
	}
}

void Title::draw() const
{
	Scene::SetBackground(ColorF{ 0.3, 0.4, 0.5 });

	FontAsset(U"TitleFont")(U"Shirous").drawAt(400, 100);

	// 現在のスコアを表示
	FontAsset(U"ScoreFont")(U"Score: {}"_fmt(getData().score)).draw(520, 540);
	FontAsset(U"ScoreFont")(U"Clickでシーン遷移").draw(960, 840);

	//Circle{ Cursor::Pos(), 50 }.draw(Palette::Orange);
}
