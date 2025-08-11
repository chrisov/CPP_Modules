#include <iostream>
#include "../inc/PmergeMe.hpp"
#include "../inc/FordJohnson.hpp"

int main(int argc, const char *argv[]) {
	PmergeMe<std::vector<int>>		*PMM;

	std::cout << utils::color("\nBefore", YLW) << ": ";
	utils::printCharArray(++argv, argc - 1);
	std::cout << std::endl;
	if (argc == 1)
		return (std::cerr << utils::color("Error", RED) << ": No parameters passed!" << std::endl, 1);
	try {
		PMM = new PmergeMe<std::vector<int>>(argv, argc - 1);
		FordJohnson<std::vector<int>>	FJ;
		PMM->getCont() = FJ.sorting(*PMM);
		// std::cout << utils::color("\nAfter", YLW) << ":  " << *PMM << std::endl;
		delete PMM;
	}
	catch (const PmergeMeException& e) {
		std::cerr << utils::color("Error", RED) << "! " << e.what() << std::endl;
	}
	return (0);
}