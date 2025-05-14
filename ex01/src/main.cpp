#include "../inc/ScavTrap.hpp"

int	main(void) {
	ScavTrap	a("Giorgos");
	ClapTrap	b("Pantelis");

	std::cout << a;
	std::cout << b;
	b.attack(a.getName());
	a.takeDamage(b.getAttackDmg());
	std::cout << a;
	std::cout << b;
	a.attack(b.getName());
	b.takeDamage(a.getAttackDmg());
	std::cout << a;
	std::cout << b;
	a.guardGate();
	std::cout << a << b;
}