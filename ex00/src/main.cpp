#include "../inc/ClapTrap.hpp"

int	main(void) {
	ClapTrap	a;
	ClapTrap	b(a);
	ClapTrap	c("Giorgos");

	std::cout << std::endl << a << b << c;

	c.attack("Default");
	b.takeDamage(c.getAttackDmg());
	std::cout << b << c;
	
	c.attack("Default");
	b.takeDamage(1);
	std::cout << b << c;
	
	c.attack("Default");
	b.takeDamage(1);
	std::cout << b << c;
	
	c.attack("Default");
	b.takeDamage(1);
	std::cout << b << c;
	
	b.beRepaired(4);
	std::cout << b << c;
}
