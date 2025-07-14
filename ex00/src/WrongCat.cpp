#include "WrongCat.hpp"

/****************************************************
*					CONSTRUCTORS					*
****************************************************/

WrongCat::WrongCat() : type("WrongCat") {
	std::cout << YLW << "WrongCat " << GRN << "constructor " << RST << "turned Animal into  " << YLW << type << RST << "!" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other) {
	std::cout << YLW << "WrongCat " << GRN << "copy constructor " << RST << "called!" << std::endl;
}

WrongCat::~WrongCat() {
	std::cout << YLW << "WrongCat " << RED << "destructor " << RST << "called!" << std::endl;
}

/****************************************************
*					OPERATORS						*
****************************************************/

WrongCat& WrongCat::operator=(const WrongCat& other) {
	if (this != &other) {
		type = other.type;
	}
	return (*this);
}

/****************************************************
*					FUNCTIONS					*
****************************************************/

void	WrongCat::makeSound(void) const {
	std::cout << "WrongMeow!" << std::endl;
}

std::string	WrongCat::getType(void) const {
	return (type);
}