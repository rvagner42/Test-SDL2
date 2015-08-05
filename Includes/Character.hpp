#ifndef CHARACTER_H
# define CHARACTER_H

# include "rpg.h"
# include "Sprite.hpp"

class Character
{
	public:
		Character(Sprite *sprite);
		Character(Character const &src);
		~Character(void);

// ----- Operators -----
		Character	&operator=(Character const &src);

// ----- Member functions -----
		void		draw(void);
		void		animate(int dirX, int dirY);

// ----- Getters -----
		Sprite		*getSprite(void) const;
		SDL_Rect	getCrop(void) const;
		int		getWidth(void) const;
		int		getHeight(void) const;
		int		getFrame(void) const;
		int		getDirection(void) const;

	private:
		Sprite		*_sprite;
		SDL_Rect	_crop;
		int		_width;
		int		_height;
		int		_frame;
		int		_direction;
};

#endif
