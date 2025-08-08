#include "../inc/Utils.hpp"
#include "../inc/RPN.hpp"

int main (int argc, char **argv) {
	RPN	rpn;	
	
	std::cout << std::endl;
	if (argc != 2)
		return (std::cerr << Utils::color("Error", RED) << ": Wrong number of parameters!\n" << std::endl, 1);
	if (!Utils::paramCheck(argv[1]))
		return (std::cerr << Utils::color("Error", RED) << ": Invalid parameter!\n" << std::endl, 1);
	rpn.parseNExecute(argv[1]);
	std::cout << argv[1] << " = " << rpn << '\n' << std::endl;
	return (0);
}