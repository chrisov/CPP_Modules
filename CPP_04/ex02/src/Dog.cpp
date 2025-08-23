#include "../inc/Dog.hpp"

/****************************************************
*					CONSTRUCTORS					*
****************************************************/

Dog::Dog() : A_Animal("", "Dog") {
	std::cout << YLW << "Dog " << GRN << "constructor " << RST << "turned Animal into a '" << YLW << type << RST << "' type!" << std::endl; 
}

Dog::Dog(const std::string& newidea) : A_Animal(newidea, "Dog") {
	std::cout << YLW << "Dog " << GRN << "constructor " << RST << "turned Animal into a '" << YLW << type << RST << "' type!" << std::endl; 
}

Dog::Dog(const Dog& other) : A_Animal(other) {
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
		if (_brain)
			delete _brain;
		_brain = new Brain(*other._brain);
	}
	return (*this);
}

/****************************************************
*					FUNCTIONS						*
****************************************************/

void	Dog::makeSound(void) const {
	std::cout << "Bark!" << std::endl;
}
