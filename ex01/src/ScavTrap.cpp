#include "../inc/ScavTrap.hpp"

/****************************************************
*					CONSTRUCTORS					*
****************************************************/

ScavTrap::ScavTrap() {
	std::cout << "Default ScavTrap constructor called" << std::endl;
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap::ClapTrap(name) {
	std::cout << "Parameterized constructor turned " << YLW << name << RST << " into a ScavTrap" << std::endl;
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
}

ScavTrap::~ScavTrap() {
	std::cout << YLW << getName() << RST << " ScavTrap "<< RED << "destructor " << RST << "called" << std::endl;
}

/****************************************************
*						OPERATORS					*
****************************************************/

std::ostream&	operator<<(std::ostream& out, const ScavTrap& obj) {
	const unsigned int maxHitPoints = 100;
	const unsigned int maxEnergyPoints = 50;
	const unsigned int barLength = 20;

	int filledHealth = (obj._hitPoints > 0) ? (obj._hitPoints * barLength) / maxHitPoints : 0;
    int emptyHealth = barLength - filledHealth;
    int filledEnergy = (obj._energyPoints > 0) ? (obj._energyPoints * barLength) / maxEnergyPoints : 0;
    int emptyEnergy = barLength - filledEnergy;

	out << YLW << obj._name << RST << " (Attack dmg: " << obj._attackDamage << ")" << std::endl;

	out << "Hit points: ";
	for (int i = 0; i < filledHealth; ++i)
		out << GRN << "#" << RST;
	for (int i = 0; i < emptyHealth; ++i)
		out << GRN << "-" << RST;
	out << " (" << obj._hitPoints << "/" << maxHitPoints << ")" << std::endl;

	out << "Energy points: ";
	for (int i = 0; i < filledEnergy; ++i)
		out << BLU << "#" << RST;
	for (int i = 0; i < emptyEnergy; ++i)
		out << BLU << "-" << RST;
	out << " (" << obj._energyPoints << "/" << maxEnergyPoints << ")" << std::endl << std::endl;
	return (out);
}

/****************************************************
*						FUNCTIONS					*
****************************************************/

void	ScavTrap::guardGate(void) {
	std::cout << YLW << this->getName() << RST << " is guarding the gate now!" << std::endl;
}