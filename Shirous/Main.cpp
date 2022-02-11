
# include <Siv3D.hpp> // OpenSiv3D v0.4.3

# include "GameMain.hpp"

void Main()
{
	Scene::Resize(1920, 1080);
	Scene::SetResizeMode(ResizeMode::Keep);
	Window::SetFullscreen(true);
	GameMain gameMain;
	while (System::Update())
	{
		gameMain.GameUpdate();
	}
}

void Update()
{

}
