#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap: public ClapTrap {
	private:
		static constexpr unsigned int	_maxHitPoints = 100;
		static constexpr unsigned int	_maxEnergyPoints = 50;
		static constexpr unsigned int	_attackDamage = 20;
		
	public:
		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap& other);
		~ScavTrap();

		ScavTrap&	operator=(const ScavTrap& other);
		
		void			guardGate(void);
		void 			attack(const std::string &target) override;
		unsigned int	getAttackDmg(void) const override;
		unsigned int	getMaxHP(void) const override;
		unsigned int	getMaxEP(void) const override;
};

std::ostream&	operator<<(std::ostream& out, const ScavTrap& obj);

#endif
