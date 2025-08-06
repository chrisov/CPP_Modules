#include "../inc/Utils.hpp"
#include "../inc/RPN.hpp"

int main (int argc, char **argv) {
	RPN	rpn;	
	
	if (argc != 2)
		return (std::cerr << Utils::color("Error", RED) << ": Wrong number of parameters!" << std::endl, 1);
	if (!Utils::paramCheck(argv[1]))
		return (std::cerr << Utils::color("Error", RED) << ": Invalid parameter!" << std::endl, 1);
	rpn.parseParam(argv[1]);
	std::cout << rpn << std::endl;
	return (0);
}