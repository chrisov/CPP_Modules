#include "../inc/ClapTrap.hpp"

int	main(void) {
	ClapTrap	a;
	ClapTrap	b(a);
	ClapTrap	c("Giorgos");

	std::cout << std::endl << a << b << c;

	c.attack(b.getName());
	b.takeDamage(c.attackDamage);
	std::cout << b << c;
	
	c.attack(b.getName());
	b.takeDamage(1);
	std::cout << b << c;
	
	c.attack(b.getName());
	b.takeDamage(1);
	std::cout << b << c;
	
	c.attack(b.getName());
	b.takeDamage(1);
	std::cout << b << c;
	
	b.beRepaired(4);
	std::cout << b << c;
}
