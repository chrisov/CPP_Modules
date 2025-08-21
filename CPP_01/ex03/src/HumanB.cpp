#include <iostream>
#include "../inc/HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name) {
	std::cout << _name << " (HumanB) was created!" << std::endl;
}

void	HumanB::setWeapon(Weapon& weapon) {
	_weapon = &weapon;
	std::cout << _name << " is wielding a " << (*_weapon).getType() << "!" << std::endl;
}

void	HumanB::attack(void) const {
	std::cout << _name << " attacks with their " << (*_weapon).getType() << std::endl;
}
