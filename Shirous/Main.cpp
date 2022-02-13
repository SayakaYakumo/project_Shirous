
# include <Siv3D.hpp> // OpenSiv3D v0.6.3
# include "Game.hpp"

void Main()
{
	
	Game game;

	game.ini();

	while (System::Update())
	{
		game.update();
		game.draw();
	}

}

