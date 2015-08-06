#include "Camera.hpp"

Camera::Camera(void): _x(-W/2 + 32), _y(-H/2 + 16)
{
	return ;
}

Camera::Camera(int start_x, int start_y): _x(start_x - W/2 + 32), _y(start_y - H/2 + 16)
{
	return ;
}

Camera::Camera(Camera const &src): _x(src.getX()), _y(src.getY())
{
	return ;
}

Camera::~Camera(void)
{
	return ;
}

// ----- Operators -----

Camera				&Camera::operator=(Camera const &src)
{
	this->_x = src.getX();
	this->_y = src.getY();
	return (*this);
}

// ----- Member functions -----

void				Camera::move(Character &ch, Map &map)
{
	const Uint8		*keys = SDL_GetKeyboardState(NULL);
	int			dirX = 0;
	int			dirY = 0;

	if (keys[SDL_SCANCODE_UP])
	{
		this->_y -= 1;
		dirY -= 1;
	}
	if (keys[SDL_SCANCODE_DOWN])
	{
		this->_y += 1;
		dirY += 1;
	}
	if (keys[SDL_SCANCODE_LEFT])
	{
		this->_x -= 2;
		dirX -= 1;
	}
	if (keys[SDL_SCANCODE_RIGHT])
	{
		this->_x += 2;
		dirX += 1;
	}

	std::vector<Tile>		tiles = map.getTiles();
	std::vector<Tile>::iterator	it = tiles.begin();
	while (it != tiles.end())
	{
		if (it->getX() < this->getX() + W && it->getX() > this->getX() - 64
			&& it->getY() < this->getY() + H && it->getY() > this->getY() - 64)
			it->draw(this->getX(), this->getY());
		it++;
	}
	ch.animate(dirX, dirY);
}

// ----- Getters -----

int				Camera::getX(void) const
{
	return (this->_x);
}

int				Camera::getY(void) const
{
	return (this->_y);
}
