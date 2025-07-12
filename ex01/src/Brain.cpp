#include "Brain.hpp"

Brain::Brain() {
	std::cout << "New Brain created and filled with ideas!" << std::endl;
	for (int i = 0; i < 100; i++)
		ideas[i] = "Woof!";
}

Brain::Brain(const Brain& other) {
	std::cout << "New Brain created and filled with copied ideas!" << std::endl;
	for (int i = 0; i < 100; i ++)
		ideas[i] = other.ideas[i];
}

Brain::~Brain() {
	std::cout << "This brain was rot and got destroyed!" << std::endl;
}
