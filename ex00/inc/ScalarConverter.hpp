#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <iomanip>
#include "Colors.hpp"

class ScalarConverter {
	
	private:
		ScalarConverter() = delete;
		ScalarConverter(const ScalarConverter& other) = delete;
		~ScalarConverter() = delete;
		
		ScalarConverter&	operator=(const ScalarConverter& other) = delete;
	
	public:
		static void	convert(char *param);
};

std::string	getType(char *str);

#endif