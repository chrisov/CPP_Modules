#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include <iostream>
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap {

	private:
		std::string _name;

		static const unsigned int	_attackDamage;
		static const unsigned int	_maxHitPoints;
		static const unsigned int	_maxEnergyPoints;

	public:
		DiamondTrap();
		DiamondTrap(std::string name);
		DiamondTrap(const DiamondTrap& other);
		~DiamondTrap() override;

		DiamondTrap&	operator=(const DiamondTrap& other);
		
		static	unsigned int	init(void); 

		void			whoAmI(void);
		std::string		getName(void) const;

		void			attack(const std::string& target) override;
		unsigned int	getAttackDmg(void) const override;
		unsigned int	getMaxHP(void) const override;
		unsigned int	getMaxEP(void) const override;
};

std::ostream&	operator<<(std::ostream& out, const DiamondTrap& obj);

#endif