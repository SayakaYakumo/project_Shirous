#include "Menu.hpp"

Menu::Menu(const InitData& init)
	: IScene{ init }
	, m_texture{ U"🐈"_emoji }
{

}

void Menu::update()
{
	if (MouseL.down())
	{
		// タイトルシーンに遷移
		changeScene(State::Game);
	}

	// マウスカーソルの移動でスコアが増加
	getData().score += static_cast<int32>(Cursor::Delta().length() * 10);
}

void Menu::draw() const
{
	Scene::SetBackground(ColorF(0.2, 0.8, 0.6));

	//m_texture.drawAt(Cursor::Pos());

	FontAsset(U"TitleFont")(U"Menu").drawAt(400, 100);
}
