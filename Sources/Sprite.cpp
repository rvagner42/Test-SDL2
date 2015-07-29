#include "Sprite.hpp"

Sprite::Sprite(SDL_Renderer *rend, std::string const &name, int x, int y, int w, int h): _texture(NULL), _rend(rend)
{
	this->_texture = IMG_LoadTexture(rend, ("Textures/" + name).c_str());
	if (this->_texture == NULL)
		std::cerr << name << " could not be loaded." << std::endl;
	this->_rect.x = x;
	this->_rect.y = y;
	this->_rect.w = w;
	this->_rect.h = h;
}

Sprite::Sprite(SDL_Renderer *rend, std::string const &name, int w, int h): _texture(NULL), _rend(rend)
{
	this->_texture = IMG_LoadTexture(rend, ("Textures/" + name).c_str());
	if (this->_texture == NULL)
		std::cerr << name << " could not be loaded." << std::endl;
	this->_rect.x = 0;
	this->_rect.y = 0;
	this->_rect.w = w;
	this->_rect.h = h;
}

Sprite::~Sprite(void)
{
	SDL_DestroyTexture(this->_texture);
}

void			Sprite::draw(void)
{
	SDL_RenderCopy(this->_rend, this->_texture, NULL, &(this->_rect));
}

void			Sprite::modPos(int x, int y)
{
	this->_rect.x += x;
	this->_rect.y += y;
}

void			Sprite::modX(int x)
{
	this->_rect.x += x;
}

void			Sprite::modY(int y)
{
	this->_rect.y += y;
}
