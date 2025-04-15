#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"

class HumanB {
public:
	HumanB(std::string name);

	std::string	name;
	std::string	Weapon;
	
	void	setWeapon(Weapon weapon);
	void	attack(void);
};

#endif
