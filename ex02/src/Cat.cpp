#include "../inc/Cat.hpp"

/****************************************************
*					CONSTRUCTORS					*
****************************************************/

Cat::Cat() : A_Animal("", "Cat") {
	std::cout << YLW << "Cat " << GRN << "constructor " << RST << "turned Animal into  " << YLW << type << RST << "!" << std::endl;
}

Cat::Cat(const std::string& newidea) : A_Animal(newidea, "Cat") {
		std::cout << YLW << "Cat " << GRN << "constructor " << RST << "turned Animal into a " << YLW << type << RST << " type!" << std::endl;
}

Cat::Cat(const Cat& other) : A_Animal(other) {
	std::cout << YLW << "Cat " << GRN << "copy constructor " << RST << "called!" << std::endl;
}

Cat::~Cat() {
	std::cout << YLW << "Cat " << RED << "destructor " << RST << "called!" << std::endl;
}

/****************************************************
*					OPERATORS						*
****************************************************/

Cat&	Cat::operator=(const Cat& other) {
	if (this != &other) {
		type = other.type;
		if (_brain)
			delete _brain;
		_brain = new Brain(*other._brain);
	}
	return (*this);
}

/****************************************************
*					FUNCTIONS						*
****************************************************/

void	Cat::makeSound(void) const {
	std::cout << "Meow!" << std::endl;
}
