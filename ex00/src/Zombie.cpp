#include "../inc/Zombie.hpp"

Zombie::Zombie(std::string name) : _name(name) {
	std::cout << "Zombie " << YLW << _name << GRN << " has been created!" << RES << std::endl;
}

void	Zombie::announce(void) {
	std::cout << YLW << this->_name << RES << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie() {
	std::cout << "Zombie " << YLW << _name << RED << " has been destroyed!" << RES << std::endl;
}
