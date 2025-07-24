#include <iostream>
#include "../inc/Colors.hpp"
#include "../inc/ScalarConverter.hpp"

int main(int argc, char **argv) {

	if (argc != 2)
		return (std::cerr << "\n" << color("Error", RED) << "! Wrong number of parameters\n" << std::endl, 1);
	ScalarConverter::convert(argv[1]);
	return (0);
}