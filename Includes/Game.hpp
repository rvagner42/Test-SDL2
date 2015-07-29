#ifndef GAME_H
# define GAME_H

# include "rpg.h"

class Game
{
	public:
		Game(void);
		~Game(void);

		void		loop(void);

	private:
		bool		_quit;
		SDL_Window	*_win;
		SDL_Renderer	*_rend;
		SDL_Event	*_event;
};

#endif
