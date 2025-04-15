
#include "../inc/HumanA.hpp"
// #include "../inc/Weapon.hpp"

HumanA::HumanA(std::string name, Weapon weapon) : name(name), Weapon(weapon) {
	std::cout << "Human named " << name << " was created, wielding a " << weapon << std::endl;
}

void	HumanA::attack(void) {
	std::cout << this->name << " attacks with their " << this->Weapon << std::endl;
}
