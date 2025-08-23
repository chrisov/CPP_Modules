#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main(void) {
	DiamondTrap	a("Dia");

	std::cout << "\n\nv-------------------------------------------v" << '\n';
	std::cout << a;
	std::cout << "^-------------------------------------------^" << "\n\n" << std::endl;
	
	a.attack("Default");
	a.whoAmI();
	
	return (0);
}