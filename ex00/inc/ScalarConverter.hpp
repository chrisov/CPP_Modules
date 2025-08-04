#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <iomanip>
#include <cmath>
#include "Colors.hpp"

class ScalarConverter {
	
	private:
		ScalarConverter() = delete;
		ScalarConverter(const ScalarConverter& other) = delete;
		~ScalarConverter() = delete;
		
		ScalarConverter&	operator=(const ScalarConverter& other) = delete;
	
	public:
		static void	convert(const char *param);
};

std::string	getType(const char *str);

#endif