#include <iostream>
#include "../inc/Colors.hpp"
#include "../inc/ScalarConverter.hpp"

int main(int argc, const char **argv) {

	if (argc > 2)
		return (std::cerr << "\n" << color("Error", RED) << "! Wrong number of parameters\n" << std::endl, 1);
	if (argc == 2)
		ScalarConverter::convert(argv[1]);
	else {
		std::cout << "\nv======================= INT =======================v" << std::endl;
		ScalarConverter::convert("0");
		std::cout << std::endl;
		ScalarConverter::convert("-42");
		std::cout << std::endl;
		ScalarConverter::convert("42");
		std::cout << std::endl;
		ScalarConverter::convert("49");
		std::cout << std::endl;
		ScalarConverter::convert("65");
		std::cout << "^===================================================^\n" << std::endl;
		
		
		std::cout << "\nv===================== DOUBLE ======================v" << std::endl;
		ScalarConverter::convert("0");
		std::cout << std::endl;
		ScalarConverter::convert("42.5");
		std::cout << std::endl;
		ScalarConverter::convert("-24");
		std::cout << std::endl;
		ScalarConverter::convert("49.");
		std::cout << std::endl;
		ScalarConverter::convert("nan");
		std::cout << std::endl;
		ScalarConverter::convert("inf");
		std::cout << std::endl;
		ScalarConverter::convert("+inf");
		std::cout << std::endl;
		ScalarConverter::convert("-inf");
		std::cout << "^===================================================^\n" << std::endl;
		
		
		std::cout << "\nv===================== FLOAT =======================v" << std::endl;
		ScalarConverter::convert("0.f");
		std::cout << std::endl;
		ScalarConverter::convert("42.5f");
		std::cout << std::endl;
		ScalarConverter::convert("-24.3f");
		std::cout << std::endl;
		ScalarConverter::convert("49.1f");
		std::cout << std::endl;
		ScalarConverter::convert("nanf");
		std::cout << std::endl;
		ScalarConverter::convert("inff");
		std::cout << std::endl;
		ScalarConverter::convert("+inff");
		std::cout << std::endl;
		ScalarConverter::convert("-inff");
		std::cout << "^===================================================^\n" << std::endl;
	}
	return (0);
}