#include "../inc/ScavTrap.hpp"

/****************************************************
*					CONSTRUCTORS					*
****************************************************/

ScavTrap::ScavTrap() : ClapTrap("Default", _maxHitPoints, _maxEnergyPoints) {
	std::cout << "Default ScavTrap constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name, _maxHitPoints, _maxEnergyPoints) {
	std::cout << "Parameterized constructor turned " << YLW << name << RST << " into a ScavTrap" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {
	std::cout << "Copy constructor created another " << YLW << other._name << RST << " ScavTrap instance" << std::endl;
}

ScavTrap::~ScavTrap() {
	std::cout << YLW << _name << RST << " ScavTrap "<< RED << "destructor " << RST << "called" << std::endl;
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

	int filledHealth = (obj.getHitPoints() > 0) ? (obj.getHitPoints() * barLength) / obj.getMaxHP() : 0;
	int emptyHealth = barLength - filledHealth;
	int filledEnergy = (obj.getEnergyPoints() > 0) ? (obj.getEnergyPoints() * barLength) / obj.getMaxEP() : 0;
	int emptyEnergy = barLength - filledEnergy;

	out << YLW << obj.getName() << RST << " (Attack dmg: " << obj.getAttackDmg() << ")" << '\n';

	out << "Hit points: ";
	for (int i = 0; i < filledHealth; ++i)
		out << GRN << "#" << RST;
	for (int i = 0; i < emptyHealth; ++i)
		out << GRN << "-" << RST;
	out << " (" << obj.getHitPoints() << "/" << obj.getMaxHP() << ")" << '\n';

	out << "Energy points: ";
	for (int i = 0; i < filledEnergy; ++i)
		out << BLU << "#" << RST;
	for (int i = 0; i < emptyEnergy; ++i)
		out << BLU << "-" << RST;
	out << " (" << obj.getEnergyPoints() << "/" << obj.getMaxEP() << ")" << std::endl;
	return (out);
}

/****************************************************
*						FUNCTIONS					*
****************************************************/

void	ScavTrap::guardGate(void) {
	std::cout << YLW << getName() << RST << " is guarding the gate now!" << std::endl;
}

void	ScavTrap::attack(const std::string &target) {
	(void)target;
	if (_energyPoints == 0)
		std::cout << "No more energy points!" << std::endl;
	else if (_hitPoints == 0)
		std::cout << _name << " is dead.." << std::endl;
	else {
		_energyPoints--;
		std::cout << "ScavTrap " << YLW << _name << RST << " attacks... ";
		if (_attackDamage == 0)
			std::cout << "It has no effect..." << std::endl;
		else if (_attackDamage <= 30)
			std::cout << "It's not very effective." << std::endl;
		else 
			std::cout << "It's super effective!" << std::endl;
	}
}

unsigned int	ScavTrap::getMaxHP(void) const {
	return (_maxHitPoints);
}

unsigned int	ScavTrap::getMaxEP(void) const {
	return (_energyPoints);
}

unsigned int	ScavTrap::getAttackDmg(void) const {
	return (_attackDamage);
}