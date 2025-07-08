#include "../inc/ScavTrap.hpp"

int	main(void) {
	ScavTrap	a("Giorgos");
	ClapTrap	b("Pantelis");

	std::cout << '\n';
	std::cout << "v-------------------------------------------v" << '\n';
	std::cout << a << '\n' << b;
	std::cout << "^-------------------------------------------^" << '\n' << std::endl;

	b.attack(a.getName());
	a.takeDamage(b.attackDamage);
	std::cout << "v-------------------------------------------v" << '\n';
	std::cout << a << '\n' << b;
	std::cout << "^-------------------------------------------^" << '\n' << std::endl;
	
	a.attack(b.getName());
	b.takeDamage(a.attackDamage);
	std::cout << "v-------------------------------------------v" << std::endl;
	std::cout << a << std::endl << b;
	std::cout << "^-------------------------------------------^" << std::endl << std::endl;
	
	a.guardGate();
	b.beRepaired(5);
	std::cout << std::endl;
	std::cout << "v-------------------------------------------v" << std::endl;
	std::cout << a << std::endl << b;
	std::cout << "^-------------------------------------------^" << std::endl << std::endl;
}