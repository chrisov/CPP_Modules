#ifndef UTILS_HPP
#define UTILS_HPP

#define RST "\033[0m"
#define RED "\033[31m"
#define GRN "\033[32m"
#define YLW "\033[33m"

#include <iostream>
#include <cstring>
	
namespace utils {
	const std::string	color(const std::string& text, const std::string& col);
	char**				split(const std::string& str, char delim);
    void				freeCharArray(char **arr);
	int					arraySize(char **arr);
}

#endif
