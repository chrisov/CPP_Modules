#include "../inc/WrongAnimal.hpp"

/****************************************************
*					CONSTRUCTORS					*
****************************************************/

WrongAnimal::WrongAnimal() : type("WrongAnimal") {
	std::cout << YLW << "WrongAnimal " << GRN << "constructor " << RST << "called!" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) : type(other.type) {
	std::cout << YLW << "WrongAnimal " << GRN << "copy constructor " << RST << "called!" << std::endl;
}

WrongAnimal::WrongAnimal(const std::string& newtype) : type(newtype) {
	std::cout << "Parameterized " << YLW << "WrongAnimal " << GRN << "constructor " << RST << "called!" << std::endl;
}

WrongAnimal::~WrongAnimal() {
	std::cout << YLW << "WrongAnimal " << RED << "destructor " << RST << "called!" << std::endl;
}

/****************************************************
*					OPERATORS						*
****************************************************/

WrongAnimal&	WrongAnimal::operator=(const WrongAnimal& other) {
	if (this != &other) {
		type = other.type;
	}
	return (*this);
}

/****************************************************
*					FUNCTIONS					*
****************************************************/

void	WrongAnimal::makeSound(void) const {
	std::cout << "WrongAnimal noises!" << std::endl;
}

std::string	WrongAnimal::getType(void) const {
	return (type);
}