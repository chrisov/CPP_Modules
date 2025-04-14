
#include "../inc/Zombie.hpp"
#include <iostream>

int	main(void)
{
	std::cout << std::endl;
	Zombie z1("Antonis");
	z1.announce();
	
	std::cout << std::endl;
	randomChump("Paraskevas");

		std::cout << std::endl;
	Zombie* z3 = newZombie("Elenanta");
	z3->announce();
	delete z3;

	std::cout << std::endl;
}