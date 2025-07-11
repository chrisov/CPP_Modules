#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal") {
	std::cout << YLW << "WrongAnimal " << GRN << "constructor " << RST << "turned Animal into  " << YLW << type << RST << "!" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) : type(other.type) {
	std::cout << YLW << "WrongAnimal " << GRN << "copy constructor " << RST << "called!" << std::endl;
}

WrongAnimal::~WrongAnimal() {
	std::cout << YLW << "WrongAnimal " << RED << "destructor " << RST << "called!" << std::endl;
}

void	WrongAnimal::makeSound(void) const {
	std::cout << "WrongAnimal noises!" << std::endl;
}

std::string	WrongAnimal::getType(void) const {
	return (type);
}