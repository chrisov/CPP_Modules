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
		std::string		_name;
		unsigned int	_hitPoints;
		unsigned int	_energyPoints;
		
		static const unsigned int	_attackDamage = 0;
		static const unsigned int	_maxHitPoints = 10;
		static const unsigned int	_maxEnergyPoints = 10;

	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(std::string name, unsigned int HP, unsigned int EP);
		ClapTrap(const ClapTrap &other);
		virtual ~ClapTrap();
		
		
		ClapTrap&		operator=(const ClapTrap& other);
		
		std::string				getName(void) const;
		unsigned int			getHitPoints(void) const;
		unsigned int			getEnergyPoints(void) const;
		void					takeDamage(unsigned int amount);
		void					beRepaired(unsigned int amount);
		
		virtual void			attack(const std::string& target);
		virtual unsigned int	getAttackDmg(void) const;
		virtual unsigned int	getMaxHP(void) const;
		virtual unsigned int	getMaxEP(void) const;
	};

std::ostream&	operator<<(std::ostream& out, const ClapTrap& obj);

#endif