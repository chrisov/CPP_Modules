#include "../inc/Dog.hpp"

/****************************************************
*					CONSTRUCTORS					*
****************************************************/

Dog::Dog() : Animal(), type("Dog") {
	std::cout << YLW << "Dog " << GRN << "constructor " << RST << "turned Animal into a " << YLW << type << RST << "!" << std::endl; 
}

Dog::Dog(const std::string idea) : Animal(idea), type("Dog") {
	std::cout << YLW << "Dog " << GRN << "constructor " << RST << "turned Animal into a " << YLW << type << RST << "!" << std::endl; 
}

Dog::Dog(const Dog& other) : Animal(other) {
	std::cout << YLW << "Dog " << GRN << "copy constructor " << RST << "called!" << std::endl;
}

Dog::~Dog() {
	std::cout << YLW << "Dog " << RED << "destructor " << RST << "called!" << std::endl;
}

/****************************************************
*					OPERATORS						*
****************************************************/

Dog&	Dog::operator=(const Dog& other) {
	if (this != &other) {
		type = other.type;
		_brain = other._brain;
	}
	return (*this);
}

/****************************************************
*					FUNCTIONS						*
****************************************************/

void	Dog::makeSound(void) const {
	std::cout << "Bark!" << std::endl;
}

std::string	Dog::getType(void) const {
	return (type);
}
