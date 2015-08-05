#ifndef MAP_H
# define MAP_H

# include "rpg.h"
# include "Tile.hpp"

class Map
{
	public:
		Map(SDL_Renderer *renderer, std::string map_name);
		Map(Map const &src);
		virtual ~Map(void);

// ----- Operators -----
		Map				&operator=(Map const &src);

// ----- Getters -----
		std::vector<Tile>		getTiles(void) const;
		int				getStartX(void) const;
		int				getStartY(void) const;

	private:
		std::vector<Tile>		_tiles;
		int				_startX;
		int				_startY;
};

#endif
