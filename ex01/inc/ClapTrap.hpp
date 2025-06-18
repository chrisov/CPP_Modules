#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

#define RST "\033[0m"
#define RED "\033[31m"
#define GRN "\033[32m"
#define YLW "\033[33m"
#define BLU "\033[34m"

class ClapTrap {

protected:
	std::string					_name;
	unsigned int				_hitPoints;
	unsigned int				_energyPoints;
	
public:
	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap &other);
	~ClapTrap();
	
	static const unsigned int	attackDamage = 20;
	static const unsigned int	maxHitPoints = 100;
	static const unsigned int	maxEnergyPoints = 50;

	friend	std::ostream&	operator<<(std::ostream& out, const ClapTrap& obj);

	ClapTrap&		operator=(const ClapTrap& other);

	virtual void	attack(const std::string &target);
	void			takeDamage(unsigned int amount);
	void			beRepaired(unsigned int amount);
	std::string		getName(void) const;
};

#endif