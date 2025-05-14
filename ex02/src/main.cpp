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
	a.attack(b.getName());
	b.takeDamage(a.getAttackDmg());
	b.beRepaired(10);
	b.guardGate();
	c.highFiveGuys();
	std::cout << a << b << c;
}