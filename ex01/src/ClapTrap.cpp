#include <iostream>

#include "../inc/ClapTrap.hpp"

/****************************************************
*					CONSTRUCTORS					*
****************************************************/

ClapTrap::ClapTrap() : _name("Default"), _hitPoints(maxHitPoints), _energyPoints(maxEnergyPoints) {
	std::cout << YLW << "Default "<< RST << "constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(maxHitPoints), _energyPoints(maxEnergyPoints) {
	std::cout << "Parameterized constructor " << GRN << "created" << RST << " a ClapTrap named " << YLW << name << RST << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) {
	*this = other;
}

ClapTrap::~ClapTrap() {
	std::cout << YLW << _name << RST << " ClapTrap "<< RED << "destructor " << RST << "called" << std::endl;
}

/****************************************************
*						OPERATORS					*
****************************************************/

ClapTrap&	ClapTrap::operator=(const ClapTrap& other) {
	std::cout << "Copy constructor called on the " << other._name << " instance" << std::endl;
	if (this != &other) {
		_name = other._name;
		_hitPoints = other._hitPoints;
		_energyPoints = other._energyPoints;
	}
	return (*this);
}

std::ostream&	operator<<(std::ostream& out, const ClapTrap& obj) {
	const unsigned int barLength = 20;

	int filledHealth = (obj.getHitPoints() > 0) ? (obj.getHitPoints() * barLength) / obj.maxHitPoints : 0;
    int emptyHealth = barLength - filledHealth;
    int filledEnergy = (obj.getEnergyPoints() > 0) ? (obj.getEnergyPoints() * barLength) / obj.maxEnergyPoints : 0;
    int emptyEnergy = barLength - filledEnergy;

	out << YLW << obj.getName() << RST << " (Attack dmg: " << obj.attackDamage << ")" << std::endl;

	out << "Hit points: ";
	for (int i = 0; i < filledHealth; ++i)
		out << GRN << "#" << RST;
	for (int i = 0; i < emptyHealth; ++i)
		out << GRN << "-" << RST;
	out << " (" << obj.getHitPoints() << "/" << obj.maxHitPoints << ")" << std::endl;

	out << "Energy points: ";
	for (int i = 0; i < filledEnergy; ++i)
		out << BLU << "#" << RST;
	for (int i = 0; i < emptyEnergy; ++i)
		out << BLU << "-" << RST;
	out << " (" << obj.getEnergyPoints() << "/" << obj.maxEnergyPoints << ")" << std::endl << std::endl;
	return (out);
}

/****************************************************
*						FUNCTIONS					*
****************************************************/

void	ClapTrap::attack(const std::string& target) {
	(void)target;
	if (_energyPoints == 0)
		std::cout << "No more energy points!" << std::endl;
	else if (_hitPoints == 0)
		std::cout << _name << " is dead.." << std::endl;
	else {
		_energyPoints--;
		std::cout << "ClapTrap " << YLW << _name << RST << " attacks... ";
		if (attackDamage == 0)
			std::cout << "It has no effect..." << std::endl;
		else if (attackDamage <= 30)
			std::cout << "It's not very effective." << std::endl;
		else 
			std::cout << "It's super effective!" << std::endl;
	}
}

void	ClapTrap::takeDamage(unsigned int amount) {
	if (amount <= _hitPoints)
		_hitPoints -= amount;
	else
		_hitPoints = 0;
	if (amount > 0)
		std::cout << YLW << _name << RED << " took some damage!" << RST << std::endl;
	if (_hitPoints == 0)
		std::cout << YLW << _name << RED << " died..." << RST << std::endl;
	std::cout << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (_energyPoints == 0)
		std::cout << "No more energy points!" << std::endl;
	else if (_hitPoints == 0)
		std::cout << _name << " is dead.." << std::endl;
	else {
		_energyPoints--;
		_hitPoints += amount;
		std::cout << YLW << _name << RST << " repairs itself!" << " (" << GRN << "+" << amount << RST << ")";
		std::cout << std::endl;
	}
}

unsigned int	ClapTrap::getAttackDmg(void) const {
	return (attackDamage);
}

std::string		ClapTrap::getName(void) const {
	return (_name);
}

unsigned int ClapTrap::getHitPoints(void) const {
	return (_hitPoints);
}

unsigned int ClapTrap::getEnergyPoints(void) const {
	return (_energyPoints);
}