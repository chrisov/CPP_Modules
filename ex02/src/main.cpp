#include <iostream>
#include "../inc/PmergeMe.hpp"
#include "../inc/FordJohnson.hpp"

int main(int argc, const char *argv[]) {
	double duration_vec;
	double duration_dq;

	if (argc == 1)
		return (std::cerr << utils::color("Error", RED) << ": No parameters passed!" << std::endl, 1);
	if (!utils::areAllNumeric(argc - 1, argv + 1))
		return (std::cerr << utils::color("Error", RED) << ": Invalid parameters passed!" << std::endl, 1);
	std::cout << "\nv=================== VECTOR ===================v" << std::endl;
	try {
		FordJohnson<std::vector<int>>	FJ;
		PmergeMe<std::vector<int>> *PMM = new PmergeMe<std::vector<int>>(++argv, argc - 1);
		std::cout << utils::color("\nBefore", YLW) << ": " << *PMM << std::endl;
	
		auto start = std::chrono::high_resolution_clock::now();
		std::vector<int> sorted_arr = FJ.sorting(*PMM);
		auto end = std::chrono::high_resolution_clock::now();

		PMM->setCont(sorted_arr);
		std::cout << utils::color("\nAfter", YLW) << ": " << *PMM << std::endl;
		std::cout << "\nNumber of comparisons: " << FJ.getComparisons() << std::endl;
		(void) start;
		(void) end;
		duration_vec = std::chrono::duration<double>(end - start).count() * 1000;
		delete PMM;
		std::cout << "^==============================================^\n" << std::endl;
	}
	catch (const PmergeMeException& e) {
		std::cerr << utils::color("Error", RED) << "! " << e.what() << std::endl;
	}


	std::cout << "\nv=================== DEQUE ====================v" << std::endl;
	try {
		FordJohnson<std::deque<int>>	FJ;
		PmergeMe<std::deque<int>> *PMM = new PmergeMe<std::deque<int>>(argv, argc - 1);
		std::cout << utils::color("\nBefore", YLW) << ": " << *PMM << std::endl;
	
		auto start = std::chrono::high_resolution_clock::now();
		std::deque<int> sorted_arr = FJ.sorting(*PMM);
		auto end = std::chrono::high_resolution_clock::now();

		PMM->setCont(sorted_arr);
		std::cout << utils::color("\nAfter", YLW) << ": " << *PMM << std::endl;
		std::cout << "\nNumber of comparisons: " << FJ.getComparisons() << std::endl;
		duration_dq = std::chrono::duration<double>(end - start).count() * 1000;
		delete PMM;
		std::cout << "^==============================================^\n" << std::endl;
	}
	catch (const PmergeMeException& e) {
		std::cerr << utils::color("Error", RED) << "! " << e.what() << std::endl;
	}
	
	std::cout << "Time vec: " << duration_vec << " (ms)" << std::endl;
	std::cout << "Time dq: " << duration_dq << " (ms)" << std::endl;
	return (0);
}
