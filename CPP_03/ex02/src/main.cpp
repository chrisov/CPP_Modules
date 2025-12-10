#include "../inc/ScavTrap.hpp"
#include "../inc/FragTrap.hpp"

int	main(void) {
	ClapTrap	a("ClapGiorgos");
	ScavTrap	b("ScavPantelis");
	FragTrap	c("FragKleanthis");

	std::cout << "\n\nv-------------------------------------------v" << '\n';
	std::cout << a << '\n' << b << '\n' << c;
	std::cout << "^-------------------------------------------^" << "\n\n" << std::endl;

	c.attack(b.getName());
	b.takeDamage(c.getAttackDmg());
	std::cout << "\n\nv-------------------------------------------v" << '\n';
	std::cout << a << '\n' << b << '\n' << c;
	std::cout << "^-------------------------------------------^" << "\n\n" << std::endl;

	a.attack(b.getName());
	b.takeDamage(a.getAttackDmg());
	b.beRepaired(10);
	b.guardGate();
	std::cout << "\n\nv-------------------------------------------v" << '\n';
	std::cout << a << '\n' << b << '\n' << c;
	std::cout << "^-------------------------------------------^" << "\n\n" << std::endl;
	
	c.attack(a.getName());
	a.takeDamage(c.getAttackDmg());
	std::cout << "\n\nv-------------------------------------------v" << '\n';
	std::cout << a << '\n' << b << '\n' << c;
	std::cout << "^-------------------------------------------^" << "\n\n" << std::endl;
	
	c.highFiveGuys();
	a.beRepaired(10);
	b.beRepaired(30);
	c.beRepaired(10);
	std::cout << "\n\nv-------------------------------------------v" << '\n';
	std::cout << a << '\n' << b << '\n' << c;
	std::cout << "^-------------------------------------------^" << "\n\n" << std::endl;
}