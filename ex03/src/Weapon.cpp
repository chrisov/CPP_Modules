
#include "../inc/Weapon.hpp"

Weapon::Weapon() {}

Weapon::Weapon(const std::string type) : _type(type) {}

const std::string	Weapon::getType(void) {
	return (_type);
}

void	Weapon::setType(std::string newType) {
	_type = newType;
}
