#ifndef COLORS_HPP
#define COLORS_HPP

#define RST "\033[0m"
#define RED "\033[31m"
#define GRN "\033[32m"
#define YLW "\033[33m"
#define MGD "\033[35m"
#define CYA "\033[36m"

#include <iostream>

inline const std::string	color(const std::string& text, const std::string& col) {
	return (col + text + RST);
}

#endif