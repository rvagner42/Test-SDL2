#include "rpg.h"
#include "Game.hpp"

int		main(void)
{
	if (SDL_Init(SDL_INIT_VIDEO) >= 0)
	{
		Game		game;

		game.loop();

		SDL_Quit();
	}
	else
		std::cerr << "Init error." << std::endl;
	return (0);
}
