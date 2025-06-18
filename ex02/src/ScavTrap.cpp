#include "../inc/ScavTrap.hpp"

/****************************************************
*					CONSTRUCTORS					*
****************************************************/

ScavTrap::ScavTrap() {
	std::cout << "Default ScavTrap constructor called" << std::endl;
	_hitPoints = maxHitPoints;
	_energyPoints = maxEnergyPoints;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	std::cout << "Parameterized constructor turned " << YLW << name << RST << " into a ScavTrap" << std::endl;
	_hitPoints = maxHitPoints;
	_energyPoints = maxEnergyPoints;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {
	std::cout << "Copy constructor created another " << YLW << other._name << RST << " ScavTrap instance" << std::endl;
	*this = other;
}

ScavTrap::~ScavTrap() {
	std::cout << YLW << getName() << RST << " ScavTrap "<< RED << "destructor " << RST << "called" << std::endl;
}

/****************************************************
*						OPERATORS					*
****************************************************/

ScavTrap&	ScavTrap::operator=(const ScavTrap& other) {
	if (this != &other) {
		_name = other._name;
		_hitPoints = other._hitPoints;
		_energyPoints = other._energyPoints;
	}
	return (*this);
}

std::ostream&	operator<<(std::ostream& out, const ScavTrap& obj) {
	const unsigned int barLength = 20;

	int filledHealth = (obj._hitPoints > 0) ? (obj._hitPoints * barLength) / obj.maxHitPoints : 0;
    int emptyHealth = barLength - filledHealth;
    int filledEnergy = (obj._energyPoints > 0) ? (obj._energyPoints * barLength) / obj.maxEnergyPoints : 0;
    int emptyEnergy = barLength - filledEnergy;

	out << YLW << obj._name << RST << " (Attack dmg: " << obj.attackDamage << ")" << std::endl;

	out << "Hit points: ";
	for (int i = 0; i < filledHealth; ++i)
		out << GRN << "#" << RST;
	for (int i = 0; i < emptyHealth; ++i)
		out << GRN << "-" << RST;
	out << " (" << obj._hitPoints << "/" << obj.maxHitPoints << ")" << std::endl;

	out << "Energy points: ";
	for (int i = 0; i < filledEnergy; ++i)
		out << BLU << "#" << RST;
	for (int i = 0; i < emptyEnergy; ++i)
		out << BLU << "-" << RST;
	out << " (" << obj._energyPoints << "/" << obj.maxEnergyPoints << ")" << std::endl << std::endl;
	return (out);
}

/****************************************************
*						FUNCTIONS					*
****************************************************/

void	ScavTrap::guardGate(void) {
	std::cout << YLW << this->getName() << RST << " is guarding the gate now!" << std::endl;
}