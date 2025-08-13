#include <iostream>
#include "../inc/PmergeMe.hpp"
#include "../inc/FordJohnson.hpp"

int main(int argc, const char *argv[]) {
	PmergeMe<std::vector<int>>		*PMM;
	FordJohnson<std::vector<int>>	FJ;

	if (argc == 1)
		return (std::cerr << utils::color("Error", RED) << ": No parameters passed!" << std::endl, 1);
	try {
		PMM = new PmergeMe<std::vector<int>>(++argv, argc - 1);
		std::vector<int> sorted_arr = FJ.sorting(*PMM);
		PMM->setCont(sorted_arr);
	}
	catch (const PmergeMeException& e) {
		std::cerr << utils::color("Error", RED) << "! " << e.what() << std::endl;
	}
	delete PMM;
	return (0);
}
