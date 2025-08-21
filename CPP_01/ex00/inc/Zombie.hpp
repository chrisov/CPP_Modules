#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>

#define RES "\033[0m"
#define RED "\033[31m"
#define GRN "\033[32m"
#define YLW "\033[33m"

class Zombie {

	private:
		std::string	_name;

	public:
		Zombie(std::string name);
		~Zombie();
		
		void	announce(void);
	};

	Zombie*	newZombie(std::string name);
	void	randomChump(std::string name);

#endif
