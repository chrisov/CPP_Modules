#include "../inc/Animal.hpp"

/****************************************************
*					CONSTRUCTORS					*
****************************************************/

Animal::Animal() : _brain(new Brain()), type("Animal") {
	std::cout << YLW << "Animal " << GRN << "constructor " << RST << "called!" << std::endl;
}

Animal::Animal(const Animal& other) : _brain(new Brain(*other._brain)), type(other.type) {
	std::cout << YLW << "Animal " << GRN << "copy constructor " << RST << "called!" << std::endl;
}

Animal::Animal(const std::string& newidea, const std::string& newtype) : _brain(new Brain(newidea)), type(newtype) {
	std::cout << YLW << "Animal " << GRN << "constructor " << RST << "with specific ideas called!" << std::endl;
}

Animal::~Animal() {
	std::cout << YLW << "Animal " << RED << "destructor " << RST << "called!" << std::endl;
	delete _brain;
}

/****************************************************
*					OPERATORS						*
****************************************************/

Animal&	Animal::operator=(const Animal& other) {
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

void	Animal::makeSound(void) const {
	std::cout << "Animal noises!" << std::endl;
}

std::string	Animal::getType(void) const {
	return (type);
}

Brain*	Animal::getBrain(void) const {
	return(_brain);
}