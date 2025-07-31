#include "../inc/easyfind.hpp"

int main(void) {
	std::vector<int> vec = {5, 10, 15, 20, 25, 30};
	std::vector<char> vecc = {'a', 'b', 'c', 'd'};

	easyfind(vec, 10);
	easyfind(vec, 11);
	easyfind(vecc, 'b');
	easyfind(vecc, 'e');
}