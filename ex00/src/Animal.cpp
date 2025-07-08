#include "Animal.hpp"

Animal::Animal() : type("Animal") {
	std::cout << "Animal constructor called!" << std::endl;
}

Animal::Animal(const Animal& other) : type(other.type) {
	std::cout << "Animal copy constructor called!" << std::endl;
}

Animal::~Animal() {
	std::cout << "Animal destructor called!" << std::endl;
}

void	Animal::makeSound(void) const {
	std::cout << "Animal noises!" << std::endl;
}

std::string	Animal::getType(void) const {
	return (type);
}