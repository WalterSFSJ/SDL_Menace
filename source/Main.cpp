#include <SDL3/SDL.h>
#include "Game.h"
#include <exception>
#include <iostream>
#include "TimeManager.h"
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
		TIME.Update();
		
		if (TIME.ShouldUpdateGame())
		{
			//playing = ! Input.Listen();
			game.Update();
			game.Render();
			TIME.ResetDeltaTime();
			game.HandleEvents();
		}
	}

	game.Release();

	return 0;
}