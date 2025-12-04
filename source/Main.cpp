#include <SDL3/SDL.h>
#include "Game.h"
#include <exception>
#include <iostream>
int main(int argc, char* argv[])
{
	Game game;

	try
	{
		game.Init();
	}
	catch (const std::exception& e)
	{
		std::cout << "Error: " << e.what();
		game.Release();
		return -1;
	}

	while (game.IsRunning())
	{
		game.HandleEvents();
		game.Update();
		game.Render();
	}

	game.Release();

	return 0;
}