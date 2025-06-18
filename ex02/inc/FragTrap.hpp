#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>

class FragTrap : public ClapTrap {
	public:
		FragTrap();
		FragTrap(const FragTrap& other);
		FragTrap(std::string name);
		~FragTrap();

		static const unsigned int	maxHitPoints = 100;
		static const unsigned int	maxEnergyPoints = 100;
		static const unsigned int	attackDamage = 30;

		FragTrap&	operator=(const FragTrap& other);

		friend std::ostream& operator<<(std::ostream& out, const FragTrap& obj);

		void	highFiveGuys(void);
};

#endif
