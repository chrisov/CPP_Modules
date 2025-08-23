#include "../inc/RPN.hpp"

int main (int argc, const char **argv) {
	RPN			rpn;
	const char	**param;
	
	std::cout << std::endl;
	if (argc > 2)
		return (std::cerr << Utils::color("Error", RED) << ": Too many parameters!\n" << std::endl, 1);
	if (argc == 1) {
		static const char *examples[] = {"8 9 * 9 - 9 - 9 - 4 - 1 +", 
										"7 7 * 7 -",
										"1 2 * 2 / 2 * 2 4 - +",
										"(1 + 1)",
										nullptr};
		param = examples;
	}
	else
		param = argv + 1;
	while (*param) {
		if (!Utils::paramCheck(*param)) {
			std::cerr << Utils::color("Error", RED) << ": Invalid parameter!" << std::endl;
			break ;
		}
		rpn.parseNExecute(*param);
		std::cout << *param << " = " << rpn << std::endl;
		rpn.emptyStack();
		param++;
	}
	std::cout << std::endl;
	return (0);
}