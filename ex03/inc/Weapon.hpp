#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>

class Weapon {

public:
	Weapon(const std::string type);

	const std::string&	getType(void);
	void				setType(std::string value);

private:
	std::string			type;
};

#endif
