#include "../inc/HumanA.hpp"
#include "../inc/Weapon.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) : _name(name), _weapon(weapon) {
	std::cout << _name << " (HumanA) was created, wielding a " << _weapon.getType() << std::endl;
}

void	HumanA::attack(void) const {
	std::cout << _name << " attacks with their " << _weapon.getType() << std::endl;
}
