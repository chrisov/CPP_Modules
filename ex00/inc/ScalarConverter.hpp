#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <iomanip>
#include "Colors.hpp"

class ScalarConverter {
	public:
		static void	convert(char *param);
};

std::string	getType(char *str);

#endif