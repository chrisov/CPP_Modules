#include "Cat.hpp"

Cat::Cat() : type("Cat") {
	std::cout << "Cat constructor called!" << std::endl;
}

Cat::Cat(const Cat& other) : type(other.type) {
	std::cout << "Cat copy constructor called!" << std::endl;
}

Cat::~Cat() {
	std::cout << "Cat destructor called!" << std::endl;
}

void	Cat::makeSound(void) const {
	std::cout << "Meow!" << std::endl;
}

std::string	Cat::getType(void) const {
	return (type);
}