
# include <Siv3D.hpp> // OpenSiv3D v0.6.3

# include "Common.hpp"
# include "Title.hpp"
# include "Menu.hpp"
# include "Game.hpp"

void Main()
{

	App manager;
	manager.add<Title>(State::Title);
	manager.add<Menu>(State::Menu);
	manager.add<Game>(State::Game);

	FontAsset::Register(U"TitleFont", FontMethod::MSDF, 50, Typeface::Heavy);
	FontAsset(U"TitleFont").setBufferThickness(4);
	FontAsset::Register(U"ScoreFont", 30, Typeface::Light);
	
	Scene::Resize(1920, 1080);
	Scene::SetResizeMode(ResizeMode::Keep);
	Window::SetFullscreen(true);
	//GameMain gameMain;
	
	while (System::Update())
	{
		//gameMain.GameUpdate();
		if (not manager.update())
		{
			break;
		}
	}
}

void Update()
{

}
