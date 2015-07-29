#include "rpg.h"

#include "Game.hpp"
/*
   void            pixel( SDL_Surface *surface, Vertex const &vertex )
   {
   Uint32 *data = (Uint32 *)surface->pixels;

   Uint32 color = vertex.getColor().getRed() * 256 * 256 + vertex.getColor().getGreen() * 256 + vertex.getColor().getBlue();

   if (vertex.getY() < 0 || vertex.getX() < 0 || vertex.getY() > H || vertex.getX() > W)
   {
   throw(std::exception());
   }
   data[ ( static_cast<int>(vertex.getY()) * surface->w ) + static_cast<int>(vertex.getX()) ] = color;
   }
 */
int		main(void)
{
	if (SDL_Init(SDL_INIT_VIDEO) >= 0)
	{
		Game		game;

		game.loop();

		SDL_Quit();
	}
	else
		std::cerr << "Init error." << std::endl;
	return (0);
}
