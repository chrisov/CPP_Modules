#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {
	
	protected:
		static const unsigned int	_attackDamage = 30;
		static const unsigned int	_maxHitPoints = 100;
		static const unsigned int	_maxEnergyPoints = 100;
	
	public:
		FragTrap();
		FragTrap(std::string name);
		FragTrap(const FragTrap& other);
		virtual ~FragTrap();

		FragTrap&	operator=(const FragTrap& other);

		void			highFiveGuys(void);
		void			attack(const std::string& target) override;
		unsigned int	getMaxHP(void) const override;
		unsigned int	getMaxEP(void) const override;
		unsigned int	getAttackDmg(void) const override;
	};
	
std::ostream&	operator<<(std::ostream& out, const FragTrap& obj);

#endif
