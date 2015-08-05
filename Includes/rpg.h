#ifndef RPG_H
# define RPG_H

# include <SDL2/SDL.h>
# include <SDL2/SDL_image.h>
# include <iostream>
# include <fstream>
# include <sstream>
# include <vector>
# include <map>
# include <algorithm>
# include <stdlib.h>

# define W 640
# define H 480

// ----- funct.cpp -----

std::vector<std::string>	split_it(std::string str, char delim);
std::string			get_file(std::string name);

#endif
