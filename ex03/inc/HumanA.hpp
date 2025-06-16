#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"

class HumanA {
public:
	HumanA(std::string name, Weapon& weapon);

	std::string	_name;
	Weapon&		_weapon;
	
	void		attack(void) const;
};

#endif
