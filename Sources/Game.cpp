#include "Game.hpp"
#include "Sprite.hpp"
#include "Map.hpp"
#include "Character.hpp"
#include "Camera.hpp"
#include "Tile.hpp"

Game::Game(void): _quit(false), _win(NULL), _rend(NULL), _event(new SDL_Event())
{
	this->_win = SDL_CreateWindow("Window", 0, 0, W, H, SDL_WINDOW_SHOWN);
	if (this->_win == NULL)
	{
		std::cerr << "Window error." << std::endl;
		this->_quit = true;
	}
	this->_rend = SDL_CreateRenderer(this->_win, -1, SDL_RENDERER_ACCELERATED);
}

Game::~Game(void)
{
	SDL_DestroyRenderer(this->_rend);
	SDL_DestroyWindow(this->_win);
	delete this->_event;
}

void			Game::loop(void)
{
	Uint32		ticks = SDL_GetTicks();
	const Uint8	*keys = SDL_GetKeyboardState(NULL);
	Character	maiwenn(new Sprite(this->_rend, "Maiwenn.png", (SDL_GetWindowSurface(this->_win)->w - 72) / 2, (SDL_GetWindowSurface(this->_win)->h - 96) / 2, 72, 96));
	int		dirX;
	int		dirY;
	Map		mappy(this->_rend, "map_test");
	Camera		cam(mappy.getStartX(), mappy.getStartY());

	while (this->_quit != true)
	{
		if (ticks + 10 < SDL_GetTicks())
		{
			dirX = 0;
			dirY = 0;
			ticks = SDL_GetTicks();
			SDL_PollEvent(this->_event);
			SDL_RenderClear(this->_rend);

			if (this->_event->type == SDL_QUIT || keys[SDL_SCANCODE_ESCAPE])
				this->_quit = true;
			cam.move(maiwenn, mappy);

			SDL_RenderPresent(this->_rend);
		}
	}
}
