#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"

class HumanB {
public:
	HumanB(std::string name);

	std::string	_name;
	Weapon*		_weapon;
	
	void	setWeapon(Weapon& weapon);
	void	attack(void) const;
};

#endif
