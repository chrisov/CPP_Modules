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
		std::string					_name;
		unsigned int				_hitPoints;
		unsigned int				_energyPoints;
		
		static const unsigned int	_attackDamage = 0;
		static const unsigned int	_maxHitPoints = 10;
		static const unsigned int	_maxEnergyPoints = 10;

	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap &other);
		~ClapTrap();
		
		ClapTrap&		operator=(const ClapTrap& other);
		
		void 			attack(const std::string &target);
		void			takeDamage(unsigned int amount);
		void			beRepaired(unsigned int amount);
		std::string		getName(void) const;
		unsigned int	getMaxHP(void) const;
		unsigned int	getMaxEP(void) const;
		unsigned int	getAttackDmg(void) const;
		unsigned int	getHitPoints(void) const;
		unsigned int	getEnergyPoints(void) const;
};

std::ostream&	operator<<(std::ostream& out, const ClapTrap& obj);

#endif