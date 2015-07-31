#include "SpriteChar.hpp"

SpriteChar::SpriteChar(SDL_Renderer *rend, std::string const &name, int x, int y, int w, int h): Sprite(rend, name, x, y, w, h)
{
	SDL_QueryTexture(this->_texture, NULL, NULL, &(this->_width), &(this->_height));
	this->_crop.x = 0;
	this->_crop.y = 0;
	this->_crop.w = this->_width / 7;
	this->_crop.h = this->_height / 4;
	this->_frame = 0;
	this->_dir = 0;
}

SpriteChar::SpriteChar(SDL_Renderer *rend, std::string const &name, int w, int h): Sprite(rend, name, w, h)
{
	SDL_QueryTexture(this->_texture, NULL, NULL, &(this->_width), &(this->_height));
	this->_crop.x = 0;
	this->_crop.y = 0;
	this->_crop.w = this->_width / 7;
	this->_crop.h = this->_height / 4;
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
		this->_crop.x = 0;
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
	this->_crop.y = this->_dir * this->_crop.h;
	this->draw();
}
