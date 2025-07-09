#include "../inc/ScavTrap.hpp"

int	main(void) {
	ScavTrap	a("ScavGiorgos");
	ClapTrap	b("ClapPantelis");

	std::cout << '\n';
	std::cout << "v-------------------------------------------v" << '\n';
	std::cout << a << '\n' << b;
	std::cout << "^-------------------------------------------^" << '\n' << std::endl;

	b.attack(a.getName());
	a.takeDamage(b.getAttackDmg());
	std::cout << "v-------------------------------------------v" << '\n';
	std::cout << a << '\n' << b;
	std::cout << "^-------------------------------------------^" << '\n' << std::endl;
	
	a.attack(b.getName());
	b.takeDamage(a.getAttackDmg());
	std::cout << "v-------------------------------------------v" << std::endl;
	std::cout << a << std::endl << b;
	std::cout << "^-------------------------------------------^" << std::endl << std::endl;
	
	a.guardGate();
	b.beRepaired(5);
	std::cout << std::endl;
	std::cout << "v-------------------------------------------v" << std::endl;
	std::cout << a << std::endl << b;
	std::cout << "^-------------------------------------------^" << '\n' << std::endl;
}
