#include <iostream>
#include "../inc/PmergeMe.hpp"

int main(int argc, const char *argv[]) {
	PmergeMe<std::vector<int>>	PMM(argv[1]);

	if (argc == 1)
		std::cerr << utils::color("Error", RED) << ": No parameters passed!" << std::endl;
	std::cout << PMM << std::endl;
}