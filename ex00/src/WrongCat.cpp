#include "../inc/WrongCat.hpp"

/****************************************************
*					CONSTRUCTORS					*
****************************************************/

WrongCat::WrongCat() : WrongAnimal("WrongCat") {
	std::cout << YLW << "WrongCat " << GRN << "constructor " << RST << "turned Animal into a " << YLW << type << RST << "!" << std::endl;
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
