#include "../inc/ClapTrap.hpp"

int	main(void) {
	ClapTrap	a;
	ClapTrap	b(a);
	ClapTrap	c("Giorgos");

	std::cout << "\n\nv-------------------------------------------v" << '\n';
	std::cout << a << '\n' << b << '\n' << c;
	std::cout << "^-------------------------------------------^\n\n" << std::endl;

	c.attack(b.getName());
	b.takeDamage(c.getAttackDmg());
	a.attack(b.getName());
	b.takeDamage(a.getAttackDmg());
	std::cout << "\n\nv-------------------------------------------v" << '\n';
	std::cout << a << '\n' << b << '\n' << c;
	std::cout << "^-------------------------------------------^\n\n" << std::endl;
	
	c.attack(b.getName());
	b.takeDamage(1);
	std::cout << "\n\nv-------------------------------------------v" << '\n';
	std::cout << a << '\n' << b << '\n' << c;
	std::cout << "^-------------------------------------------^\n\n" << std::endl;
	
	c.attack(a.getName());
	a.takeDamage(1);
	c.attack(b.getName());
	b.takeDamage(1);
	std::cout << "\n\nv-------------------------------------------v" << '\n';
	std::cout << a << '\n' << b << '\n' << c;
	std::cout << "^-------------------------------------------^\n\n" << std::endl;
	
	c.attack(b.getName());
	b.takeDamage(1);
	std::cout << "\n\nv-------------------------------------------v" << '\n';
	std::cout << a << '\n' << b << '\n' << c;
	std::cout << "^-------------------------------------------^\n\n" << std::endl;
	
	b.beRepaired(4);
	std::cout << "\n\nv-------------------------------------------v" << '\n';
	std::cout << a << '\n' << b << '\n' << c;
	std::cout << "^-------------------------------------------^\n\n" << std::endl;
}
