#include "../inc/ScalarConverter.hpp"

void	ScalarConverter::convert(const char* param) {
	std::string	type = getType(param);
	double		num = 0.0;

	std::cout << std::fixed << std::setprecision(1);
	if (type == "int")
		num = std::atoi(param);
	else if(type == "double")
		num = std::strtod(param, nullptr);
	else if(type == "float")
		num = std::strtof(param, nullptr);
	if (num < 0 || (num >= 0 && num <= 31) || num == 127 || num == INFINITY || std::isnan(num))
		std::cout << color("char", YLW) << ": " << color("Non-displayable", RED) << " character!" << std::endl;
	else
		std::cout << color("char", YLW) << ": '" << static_cast<char>(num) << "'" << std::endl;
	if (num == INFINITY || num == -INFINITY || std::isnan(num))
		std::cout << color("int", YLW) << ": " << color("Non-displayable", RED) << " character!" << std::endl;
	else
		std::cout << color("int", YLW) << ": " << static_cast<int>(num) << std::endl;
	std::cout << color("float", YLW) << ": " << static_cast<float>(num) << 'f' << std::endl;
	std::cout << color("double", YLW) << ": " << static_cast<double>(num) << std::endl;
}