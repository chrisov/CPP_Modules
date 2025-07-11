#include "Animal.hpp"

Animal::Animal() : type("Animal") {
	std::cout << YLW << "Animal " << GRN << "constructor " << RST << "called!" << std::endl;
}

Animal::Animal(const Animal& other) : type(other.type) {
	std::cout << YLW << "Animal " << GRN << "copy constructor " << RST << "called!" << std::endl;
}

Animal::~Animal() {
	std::cout << YLW << "Animal " << RED << "destructor " << RST << "called!" << std::endl;
}

void	Animal::makeSound(void) const {
	std::cout << "Animal noises!" << std::endl;
}

std::string	Animal::getType(void) const {
	return (type);
}