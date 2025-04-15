
#include "../inc/Weapon.hpp"

Weapon::Weapon(const std::string type) : type(type){
	std::cout << type << " was generated!" << std::endl;
}

const std::string&	Weapon::getType(void) {
	return (type);
}

void	Weapon::setType(std::string value) {
	std::cout << "Weapon is set to " << value << std::endl;
	this->type = value;
}
