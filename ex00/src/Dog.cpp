#include "Dog.hpp"

Dog::Dog() : type("Dog") {
	std::cout << "Dog constructor called!" << std::endl; 
}

Dog::Dog(const Dog& other) : type(other.type) {
	std::cout << "Dog copy constructor called!" << std::endl;
}

Dog::~Dog() {
	std::cout << "Dog destructor called!" << std::endl;
}

void	Dog::makeSound(void) const {
	std::cout << "Bark!" << std::endl;
}

std::string	Dog::getType(void) const {
	return (type);
}