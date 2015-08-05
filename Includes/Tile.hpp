#ifndef TILE_H
# define TILE_H

# include "Sprite.hpp"

class Tile
{
	public:
		Tile(Sprite *sprite, int x, int y, bool walkable);
		Tile(Tile const &src);
		virtual ~Tile(void);

// ----- Operators -----
		Tile		&operator=(Tile const &src);
		bool		operator<(Tile const &src) const;

// ----- Member functions -----
		void		draw(int offset_x, int offset_y);

// ----- Getters & Setters -----
		Sprite		*getSprite(void) const;
		int		getX(void) const;
		int		getY(void) const;
		bool		isWalkable(void) const;

	private:
		Sprite		*_sprite;
		int		_x;
		int		_y;
		bool		_walkable;
};

#endif
