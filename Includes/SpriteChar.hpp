#ifndef SPRITECHAR_H
# define SPRITECHAR_H

# include "rpg.h"
# include "Sprite.hpp"

class SpriteChar : public Sprite
{
	public:
		SpriteChar(SDL_Renderer *rend, std::string const &name, int x, int y, int w, int h);
		SpriteChar(SDL_Renderer *rend, std::string const &name, int w, int h);
		~SpriteChar(void);

		void		draw(void);
		void		animate(int dirX, int dirY);

	private:
		SDL_Rect	_crop;
		int		_width;
		int		_height;
		int		_frame;
		int		_dir;
};

#endif
