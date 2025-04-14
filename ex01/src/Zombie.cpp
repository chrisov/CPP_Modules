#include "../inc/Zombie.hpp"

Zombie::Zombie(std::string name) : _name(name) {
	std::cout << "Zombie " << _name << GREEN << " has been created!" << RES << std::endl;
}

void	Zombie::announce(void) {
	std::cout << this->_name <<": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie() {
	std::cout << "Zombie " << _name << RED << " has been destroyed!" << RES << std::endl;
}
