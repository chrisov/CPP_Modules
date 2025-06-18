#include "../inc/ScavTrap.hpp"

/****************************************************
*					CONSTRUCTORS					*
****************************************************/

ScavTrap::ScavTrap() {
	std::cout << "Default ScavTrap constructor called" << std::endl;
	// _hitPoints = 100;
	// _energyPoints = 50;	
	// _attackDamage = 20;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap::ClapTrap(name) {
	std::cout << "Parameterized constructor turned " << YLW << name << RST << " into a ScavTrap" << std::endl;
	// _hitPoints = 100;
	// _energyPoints = 50;
	// _attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap::ClapTrap(other) {
	std::cout << "Copy constructor created another " << YLW << other._name << RST << " ScavTrap instance" << std::endl;
	*this = other;
}

ScavTrap::~ScavTrap() {
	std::cout << YLW << _name << RST << " ScavTrap "<< RED << "destructor " << RST << "called" << std::endl;
}

/****************************************************
*						OPERATORS					*
****************************************************/

ScavTrap&	ScavTrap::operator=(const ScavTrap& other) {
	if (this != &other) {
		this->_name = other._name;
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		// this->_attackDamage = other._attackDamage;
	}
	return (*this);
}

std::ostream&	operator<<(std::ostream& out, const ScavTrap& obj) {
	const unsigned int barLength = 20;

	int filledHealth = (obj._hitPoints > 0) ? (obj._hitPoints * barLength) / obj.maxHitPoints : 0;
    int emptyHealth = barLength - filledHealth;
    int filledEnergy = (obj._energyPoints > 0) ? (obj._energyPoints * barLength) / obj.maxEnergyPoints : 0;
    int emptyEnergy = barLength - filledEnergy;

	out << YLW << obj._name << RST << " (Attack dmg: " << obj._attackDamage << ")" << std::endl;

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

void	ScavTrap::attack(const std::string &target) {
	(void)target;
	if (this->_energyPoints == 0)
		std::cout << "No more energy points!" << std::endl;
	else if (this->_hitPoints == 0)
		std::cout << this->_name << " is dead.." << std::endl;
	else {
		this->_energyPoints--;
		std::cout << "ScavTrap " << YLW << this->_name << RST << " attacks... ";
		if (this->_attackDamage == 0)
			std::cout << "It has no effect..." << std::endl;
		else if (this->_attackDamage == 20)
			std::cout << "It's not very effective." << std::endl;
		else 
			std::cout << "It's super effective!" << std::endl;
	}
}