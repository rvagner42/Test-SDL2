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

Sprite::Sprite(Sprite const &src)
{
	this->_texture = src.getTexture();
	this->_rend = src.getRenderer();
	this->_rect = src.getRect();
}

Sprite::~Sprite(void)
{
	SDL_DestroyTexture(this->_texture);
}

// ----- Operators -----

Sprite			&Sprite::operator=(Sprite const &src)
{
	this->_texture = src.getTexture();
	this->_rend = src.getRenderer();
	this->_rect = src.getRect();
	return (*this);
}

// ----- Member functions -----

void			Sprite::draw(void)
{
	SDL_RenderCopy(this->_rend, this->_texture, NULL, &(this->_rect));
}

void			Sprite::draw(SDL_Rect *crop)
{
	SDL_RenderCopy(this->_rend, this->_texture, crop, &(this->_rect));
}

void			Sprite::drawPos(int x, int y)
{
	SDL_Rect tmp = this->getRect();
	tmp.x = x;
	tmp.y = y;
	SDL_RenderCopy(this->_rend, this->_texture, NULL, &(tmp));
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

// ----- Getters -----

SDL_Texture		*Sprite::getTexture(void) const
{
	return (this->_texture);
}

SDL_Renderer		*Sprite::getRenderer(void) const
{
	return (this->_rend);
}

SDL_Rect		Sprite::getRect(void) const
{
	return (this->_rect);
}
