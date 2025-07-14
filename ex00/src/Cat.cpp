#include "../inc/Cat.hpp"

/****************************************************
*					CONSTRUCTORS					*
****************************************************/

Cat::Cat() : Animal("Cat") {
	std::cout << YLW << "Cat " << GRN << "constructor " << RST << "turned Animal into a " << YLW << type << RST << "!" << std::endl;
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
