#include "../inc/Animal.hpp"

/****************************************************
*					CONSTRUCTORS					*
****************************************************/

A_Animal::A_Animal() : _brain(new Brain()), type("A_Animal") {
	std::cout << YLW << "A_Animal " << GRN << "constructor " << RST << "called!" << std::endl;
}

A_Animal::A_Animal(const A_Animal& other) : _brain(new Brain(*other._brain)), type(other.type) {
	std::cout << YLW << "A_Animal " << GRN << "copy constructor " << RST << "called!" << std::endl;
}

A_Animal::A_Animal(const std::string& newidea, const std::string& newtype) : _brain(new Brain(newidea)), type(newtype) {
	std::cout << "Parameterized " << YLW << "A_Animal " << GRN << "constructor " << RST << "with specific ideas called!" << std::endl;
}

A_Animal::~A_Animal() {
	std::cout << YLW << "A_Animal " << RED << "destructor " << RST << "called!" << std::endl;
	if (_brain)
		delete _brain;
}

/****************************************************
*					OPERATORS						*
****************************************************/

A_Animal&	A_Animal::operator=(const A_Animal& other) {
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

std::string	A_Animal::getType(void) const {
	return (type);
}

Brain*	A_Animal::getBrain(void) const {
	return(_brain);
}