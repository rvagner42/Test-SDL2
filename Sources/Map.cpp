#include "Map.hpp"

Map::Map(SDL_Renderer *renderer, std::string map_name)
{
	std::string						file;
	std::vector<std::string>				split;
	std::vector<std::string>::iterator			it;
	std::map<std::string, std::vector<std::string> >	tile_log;
	std::map<std::string, Sprite *>				sprite_log;

	file = get_file("Maps/" + map_name);
	split = split_it(file, '\n');
	it = split.begin();
	while (*it != "COORD")
	{
		std::vector<std::string>		tmp = split_it(*it, ';');
		std::vector<std::string>::iterator	itmp = tmp.begin();
		std::string				tmp_str = *itmp;
		tmp.erase(itmp);
		tile_log[tmp_str] = tmp;
		sprite_log[tmp_str] = new Sprite(renderer, *(tmp.begin()), 64, 64);
		it++;
	}
	it++;
	std::vector<std::string>			coord = split_it(*it, ';');
	std::vector<std::string>::iterator		it_coord = coord.begin();
	int	tmpX = strtol((*it_coord).c_str(), NULL, 10);
	it_coord++;
	int	tmpY = strtol((*it_coord).c_str(), NULL, 10);
	this->_startX = (tmpX - tmpY) * 32;
	this->_startY = (tmpX + tmpY) * 16;
	it++; it++;
	int y = 0;
	while (it != split.end())
	{
		int					x = 0;
		std::vector<std::string>		line = split_it(*it, ' ');
		std::vector<std::string>::iterator	it_line = line.begin();
		while (it_line != line.end())
		{
			std::vector<std::string>::iterator	itmp = tile_log[*it_line].begin();
			itmp++;
			bool					walk = (*itmp == "1");
			this->_tiles.push_back(Tile(sprite_log[*it_line], x, y, walk));
			it_line++;
			x++;
		}
		it++;
		y++;
	}
	std::sort(this->_tiles.begin(), this->_tiles.end());
}

Map::Map(Map const &src)
{
	this->_tiles = src.getTiles();
	this->_startX = src.getStartX();
	this->_startY = src.getStartY();
}

Map::~Map(void)
{
	return ;
}

// ----- Operators -----

Map					&Map::operator=(Map const &src)
{
	this->_tiles = src.getTiles();
	this->_startX = src.getStartX();
	this->_startY = src.getStartY();
	return (*this);
}

// ----- Getters -----

std::vector<Tile>			Map::getTiles(void) const
{
	return (this->_tiles);
}

int					Map::getStartX(void) const
{
	return (this->_startX);
}

int					Map::getStartY(void) const
{
	return (this->_startY);
}
