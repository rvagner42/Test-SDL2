#include "SpriteChar.hpp"

SpriteChar::SpriteChar(SDL_Renderer *rend, std::string const &name, int x, int y, int w, int h): Sprite(rend, name, x, y, w, h)
{
	SDL_QueryTexture(this->_texture, NULL, NULL, &(this->_width), &(this->_height));
	this->_crop.x = 0;
	this->_crop.y = 0;
	this->_crop.w = this->_width / 12;
	this->_crop.h = this->_height;
	this->_frame = 0;
	this->_dir = 0;
}

SpriteChar::SpriteChar(SDL_Renderer *rend, std::string const &name, int w, int h): Sprite(rend, name, w, h)
{
	SDL_QueryTexture(this->_texture, NULL, NULL, &(this->_width), &(this->_height));
	this->_crop.x = 0;
	this->_crop.y = 0;
	this->_crop.w = this->_width / 12;
	this->_crop.h = this->_height;
	this->_frame = 0;
	this->_dir = 0;
}

SpriteChar::~SpriteChar(void)
{
	return ;
}

void			SpriteChar::draw(void)
{
	SDL_RenderCopy(this->_rend, this->_texture, &(this->_crop), &(this->_rect));
}

void			SpriteChar::animate(int dirX, int dirY)
{
	if (dirX == 0 && dirY == 0)
	{
		this->_crop.x = this->_dir * (this->_width / 4);
		this->_frame = 0;
	}
	else
	{
		this->_dir = 0;
		if (dirY == -1)
			this->_dir = 2;
		if (dirX == 1)
			this->_dir = 1;
		if (dirX == -1)
			this->_dir = 3;
		(this->_frame == 32) ? this->_frame = 0 : this->_frame++;
		this->_crop.x = this->_dir * (this->_width / 4);
		if (this->_frame < 8)
			this->_crop.x += this->_width / 12;
		else if (this->_frame > 15 && this->_frame < 24)
			this->_crop.x += this->_width / 6;
	}
	this->draw();
}
