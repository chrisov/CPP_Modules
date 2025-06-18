#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap: public ClapTrap {
	public:
		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap& other);
		~ScavTrap();

		static const unsigned int	maxHitPoints = 100;
		static const unsigned int	maxEitPoints = 50;
		static const unsigned int	attackDamage = 20;

		friend std::ostream&	operator<<(std::ostream& out, const ScavTrap& obj);
		
		ScavTrap&	operator=(const ScavTrap& other);
		
		void	guardGate(void);
};

#endif
