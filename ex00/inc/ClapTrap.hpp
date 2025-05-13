#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

#define RST "\033[0m"
#define RED "\033[31m"
#define GRN "\033[32m"
#define YLW "\033[33m"
#define BLU "\033[34m"

class ClapTrap {

private:
	std::string		_name;
	unsigned int	_hitPoints;
	unsigned int	_energyPoints;
	unsigned int	_attackDamage;

public:
	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap &other);
	~ClapTrap();

	friend	std::ostream&	operator<<(std::ostream& out, const ClapTrap& obj);

	ClapTrap&		operator=(const ClapTrap& other);

	void 			attack(const std::string &target);
	void			takeDamage(unsigned int amount);
	void			beRepaired(unsigned int amount);
	std::string		getName(void) const;
	unsigned int	getAttackDmg(void) const;
};

#endif