#include "../inc/ScavTrap.hpp"
#include "../inc/FragTrap.hpp"

int	main(void) {
	ClapTrap	a("Giorgos");
	ScavTrap	b("Pantelis");
	FragTrap	c("Kleanthis");

	std::cout << a << b << c;
	c.attack(b.getName());
	b.takeDamage(c.getAttackDmg());
	std::cout << a << b << c;

	// b.attack(a.getName());
	// a.takeDamage(b.getAttackDmg());
	// std::cout << a;
	// std::cout << b;
	// a.attack(b.getName());
	// b.takeDamage(a.getAttackDmg());
	// std::cout << a;
	// std::cout << b;
	// a.guardGate();
	// std::cout << a << b;
}