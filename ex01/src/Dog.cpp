#include "Dog.hpp"

Dog::Dog() : type("Dog") {
	std::cout << YLW << "Dog " << GRN << "constructor " << RST << "turned Animal into a " << YLW << type << RST << "!" << std::endl; 
}

Dog::Dog(const Dog& other) : Animal(other) {
	std::cout << YLW << "Dog " << GRN << "copy constructor " << RST << "called!" << std::endl;
}

Dog::~Dog() {
	std::cout << YLW << "Dog " << RED << "destructor " << RST << "called!" << std::endl;
}

void	Dog::makeSound(void) const {
	std::cout << "Bark!" << std::endl;
}

std::string	Dog::getType(void) const {
	return (type);
}