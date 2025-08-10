#include <iostream>
#include "../inc/PmergeMe.hpp"

int main(int argc, const char *argv[]) {
	PmergeMe<std::vector<int>>	*PMM;

	if (argc == 1)
		return (std::cerr << utils::color("Error", RED) << ": No parameters passed!" << std::endl, 1);
	try {
		PMM = new PmergeMe<std::vector<int>>(++argv, argc - 1);
		std::cout << utils::color("\nBefore", YLW) << ": " << *PMM << std::endl;
		std::cout << utils::color("\nAfter", YLW) << ":  " << *PMM << std::endl;
		delete PMM;
	}
	catch (const PmergeMeException& e) {
		std::cerr << utils::color("Error", RED) << "! " << e.what() << std::endl;
	}
}