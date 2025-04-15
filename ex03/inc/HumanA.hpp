#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"

class HumanA {
public:
	HumanA(std::string name, Weapon weapon);

	std::string	name;
	std::string	Weapon;
	
	void	attack(void);
};

#endif
