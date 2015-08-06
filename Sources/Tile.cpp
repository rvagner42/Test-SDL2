#include "Tile.hpp"

Tile::Tile(Sprite *sprite, int x, int y, bool walkable): _sprite(sprite), _x((x - y) * 32), _y((x + y) * 16), _walkable(walkable)
{
	return ;
}

Tile::Tile(Tile const &src): _sprite(src.getSprite())
{
	this->_x = src.getX();
	this->_y = src.getY();
	this->_walkable = src.isWalkable();
}

Tile::~Tile(void)
{
	return ;
}

// ----- Operators -----

Tile			&Tile::operator=(Tile const &src)
{
	this->_sprite = src.getSprite();
	this->_x = src.getX();
	this->_y = src.getY();
	this->_walkable = src.isWalkable();
	return (*this);
}

bool			Tile::operator<(Tile const &rhs) const
{
	return (this->getY() < rhs.getY());
}

// ----- Member functions -----

void			Tile::draw(int offset_x, int offset_y)
{
	this->_sprite->drawPos(this->getX() - offset_x, this->getY() - offset_y);
}

// ----- Getters & Setters -----

Sprite			*Tile::getSprite(void) const
{
	return (this->_sprite);
}

int			Tile::getX(void) const
{
	return (this->_x);
}

int			Tile::getY(void) const
{
	return (this->_y);
}

bool			Tile::isWalkable(void) const
{
	return (this->_walkable);
}
