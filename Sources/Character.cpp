#include "Character.hpp"

Character::Character(Sprite *sprite): _sprite(sprite)
{
	SDL_QueryTexture(this->_sprite->getTexture(), NULL, NULL, &(this->_width), &(this->_height));
	this->_crop.x = 0;
	this->_crop.y = 0;
	this->_crop.w = this->_width / 7;
	this->_crop.h = this->_height / 4;
	this->_frame = 0;
	this->_direction = 0;
}

Character::Character(Character const &src): _sprite(src.getSprite())
{
	this->_crop = src.getCrop();
	this->_width = src.getWidth();
	this->_height = src.getHeight();
	this->_frame = src.getFrame();
	this->_direction = src.getDirection();
}

Character::~Character(void)
{
	return ;
}

// ----- Operators -----

Character		&Character::operator=(Character const &src)
{
	this->_sprite = src.getSprite();
	this->_crop = src.getCrop();
	this->_width = src.getWidth();
	this->_height = src.getHeight();
	this->_frame = src.getFrame();
	this->_direction = src.getDirection();
	return (*this);
}

// ----- Member functions -----

void			Character::draw(void)
{
	this->_sprite->draw(&(this->_crop));
}

void			Character::animate(int dirX, int dirY)
{
	if (dirX == 0 && dirY == 0)
	{
		this->_crop.x = 0;
		this->_frame = 0;
	}
	else
	{
		this->_direction = 0;
		if (dirY == -1)
			this->_direction = 2;
		if (dirX == 1)
			this->_direction = 1;
		if (dirX == -1)
			this->_direction = 3;
		(this->_frame == 42) ? this->_frame = 0 : this->_frame++;
		if (this->_frame < 6)
			this->_crop.x = this->_crop.w;
		else if (this->_frame >= 6 && this->_frame < 12)
			this->_crop.x = 2 * this->_crop.w;
		else if (this->_frame >= 12 && this->_frame < 18)
			this->_crop.x = 3 * this->_crop.w;
		else if (this->_frame >= 18 && this->_frame < 24)
			this->_crop.x = 4 * this->_crop.w;
		else if (this->_frame >= 24 && this->_frame < 30)
			this->_crop.x = 5 * this->_crop.w;
		else if (this->_frame >= 30 && this->_frame < 36)
			this->_crop.x = 6 * this->_crop.w;
		else if (this->_frame >= 36 && this->_frame < 42)
			this->_crop.x = 0;
	}
	this->_crop.y = this->_direction * this->_crop.h;
	this->draw();
}

// ----- Getters -----

Sprite			*Character::getSprite(void) const
{
	return (this->_sprite);
}

SDL_Rect		Character::getCrop(void) const
{
	return (this->_crop);
}

int			Character::getWidth(void) const
{
	return (this->_width);
}

int			Character::getHeight(void) const
{
	return (this->_height);
}

int			Character::getFrame(void) const
{
	return (this->_frame);
}

int			Character::getDirection(void) const
{
	return (this->_direction);
}
