#include "Game.hpp"
#include "Sprite.hpp"
#include "SpriteChar.hpp"

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
	Sprite		grass(this->_rend, "grass.bmp", 2000, 1200);
	SpriteChar	maiwenn(this->_rend, "Maiwenn.png", (SDL_GetWindowSurface(this->_win)->w - 72) / 2, (SDL_GetWindowSurface(this->_win)->h - 96) / 2, 72, 96);
	int		dirX;
	int		dirY;

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
			if (keys[SDL_SCANCODE_UP])
			{
				grass.modY(2);
				dirY -= 1;
			}
			if (keys[SDL_SCANCODE_DOWN])
			{
				grass.modY(-2);
				dirY += 1;
			}
			if (keys[SDL_SCANCODE_LEFT])
			{
				grass.modX(2);
				dirX -= 1;
			}
			if (keys[SDL_SCANCODE_RIGHT])
			{
				grass.modX(-2);
				dirX += 1;
			}
			grass.draw();
			maiwenn.animate(dirX, dirY);

			SDL_RenderPresent(this->_rend);
		}
	}
}
