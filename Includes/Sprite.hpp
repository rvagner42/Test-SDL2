#ifndef SPRITE_H
# define SPRITE_H

# include "rpg.h"

class Sprite
{
	public:
		Sprite(SDL_Renderer *rend, std::string const &name, int x, int y, int w, int h);
		Sprite(SDL_Renderer *rend, std::string const &name, int w, int h);
		~Sprite(void);

		void		draw(void);
		void		modX(int x);
		void		modY(int y);
		void		modPos(int x, int y);

	protected:
		SDL_Texture	*_texture;
		SDL_Renderer	*_rend;
		SDL_Rect	_rect;
};

#endif
