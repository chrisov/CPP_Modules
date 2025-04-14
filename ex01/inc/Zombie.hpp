#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>

#define GREEN "\033[32m"
#define RED "\033[31m"
#define RES "\033[0m"

class Zombie {

private:
	std::string	_name;

public:
	Zombie(std::string name);
	~Zombie();
	
	void	announce(void);
};

Zombie*	newZombie(std::string name);
Zombie*	zombieHorde(int N, std::string name);

#endif
