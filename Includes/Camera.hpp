#ifndef CAMERA_H
# define CAMERA_H

# include "rpg.h"
# include "Character.hpp"
# include "Map.hpp"

class Camera
{
	public:
		Camera(void);
		Camera(int start_x, int start_y);
		Camera(Camera const &src);
		virtual ~Camera(void);

// ----- Operators -----
		Camera		&operator=(Camera const &src);

// ----- Member functions -----
		void		move(Character &ch, Map &map);

// ----- Getters -----
		int		getX(void) const;
		int		getY(void) const;

	private:
		int		_x;
		int		_y;
};

#endif
