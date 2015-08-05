#include "rpg.h"

std::vector<std::string>	split_it(std::string str, char delim)
{
	std::istringstream			istr(str);
	std::string				tmp;
	std::vector<std::string>		ret;

	while (getline(istr, tmp, delim))
	{
		ret.push_back(tmp);
	}
	return (ret);
}

std::string			get_file(std::string name)
{
	std::ifstream		ifs(name.c_str());
	std::string		ret;
	std::stringstream	sstr;

	sstr << ifs.rdbuf();
	ret = sstr.str();
	ifs.close();
	return (ret);
}
/*
int				main(void)
{
	std::string						file;
	std::vector<std::string>				split;
	std::map<std::string, std::vector<std::string> >	tile_log;

	file = get_file("../Maps/map_test");
	split = split_it(file, '\n');
	std::vector<std::string>::iterator	it = split.begin();
	while (*it != "COORD")
	{
		std::vector<std::string>		tmp = split_it(*it, ';');
		std::vector<std::string>::iterator	itmp = tmp.begin();
		std::string				tmp_str = *itmp;
		tmp.erase(itmp);
		tile_log[tmp_str] = tmp;
		it++;
	}
	it++;
	std::vector<std::string>	coord = split_it(*it, ';');
	std::vector<std::string>::iterator	it_coord = coord.begin();
	int	start_x = strtol((*it_coord).c_str(), NULL, 10);
	it_coord++;
	int	start_y = strtol((*it_coord).c_str(), NULL, 10);
	std::cout << "The starting coordinates are: " << start_x << ";" << start_y << std::endl;
	it++;
	it++;
	while (it != split.end())
	{
		std::vector<std::string>	line = split_it(*it, ' ');
		std::vector<std::string>::iterator	it_line = line.begin();
		while (it_line != line.end())
		{
			std::vector<std::string>::iterator	itmp = tile_log[*it_line].begin();
			std::cout << *it_line << " ";
			std::cout << *itmp << " ";
			itmp++;
			std::cout << *itmp << std::endl;
			it_line++;
		}
		it++;
	}
	return (0);
}*/
