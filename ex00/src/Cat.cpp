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

void	Cat::makeSound(void) {
	std::cout << "Meow!" << std::endl;
}