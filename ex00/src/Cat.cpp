#include "Cat.hpp"

/****************************************************
*					CONSTRUCTORS					*
****************************************************/

Cat::Cat() : Animal(), type("Cat") {
	std::cout << YLW << "Cat " << GRN << "constructor " << RST << "turned Animal into  " << YLW << type << RST << "!" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other) {
	std::cout << YLW << "Cat " << GRN << "copy constructor " << RST << "called!" << std::endl;
}

Cat::~Cat() {
	std::cout << YLW << "Cat " << RED << "destructor " << RST << "called!" << std::endl;
}

/****************************************************
*					OEPRATORS						*
****************************************************/

Cat&	Cat::operator=(const Cat& other) {
	if (this != &other) {
		type = other.type;
	}
	return (*this);
}

/****************************************************
*					FUNCTIONS						*
****************************************************/

void	Cat::makeSound(void) const {
	std::cout << "Meow!" << std::endl;
}

std::string	Cat::getType(void) const {
	return (type);
}