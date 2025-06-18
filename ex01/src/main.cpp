#include "../inc/ScavTrap.hpp"

int	main(void) {
	ScavTrap	a("Giorgos");
	ClapTrap	b("Pantelis");

	std::cout << std::endl << a << b;

	b.attack(a.getName());
	a.takeDamage(b.attackDamage);
	std::cout << a << b;
	
	a.attack(b.getName());
	b.takeDamage(a.attackDamage);
	std::cout << a << b;
	
	a.guardGate();
	b.beRepaired(5);
	std::cout << std::endl << a << b;
}