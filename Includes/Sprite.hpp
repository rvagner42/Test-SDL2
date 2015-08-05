#ifndef SPRITE_H
# define SPRITE_H

# include "rpg.h"

class Sprite
{
	public:
		Sprite(SDL_Renderer *rend, std::string const &name, int x, int y, int w, int h);
		Sprite(SDL_Renderer *rend, std::string const &name, int w, int h);
		Sprite(Sprite const &src);
		virtual ~Sprite(void);

// ----- Operators -----
		Sprite		&operator=(Sprite const &src);

// ----- Member functions -----
		void		draw(void);
		void		draw(SDL_Rect *crop);
		void		drawPos(int x, int y);
		void		modX(int x);
		void		modY(int y);
		void		modPos(int x, int y);

// ----- Getters & Setters -----
		SDL_Texture	*getTexture(void) const;
		SDL_Renderer	*getRenderer(void) const;
		SDL_Rect	getRect(void) const;

	protected:
		SDL_Texture	*_texture;
		SDL_Renderer	*_rend;
		SDL_Rect	_rect;
};

#endif
