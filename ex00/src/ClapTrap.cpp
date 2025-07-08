#include <iostream>

#include "../inc/ClapTrap.hpp"

/****************************************************
*					CONSTRUCTORS					*
****************************************************/

ClapTrap::ClapTrap() : _name("Default"), _hitPoints(maxHitPoints), _energyPoints(maxEnergyPoints) {
	std::cout << YLW << "Default "<< RST << "constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(maxHitPoints), _energyPoints(maxEnergyPoints) {
	std::cout << "Parameterized constructor " << GRN << "created " << RST << "ClapTrap named " << YLW << name << RST << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) {
	std::cout << "Copy constructor called on the " << YLW << other._name << RST << " instance" << std::endl;
	*this = other;
}

ClapTrap::~ClapTrap() {
	std::cout << "Destructor called" << std::endl;
}

/****************************************************
*						OPERATORS					*
****************************************************/

ClapTrap&	ClapTrap::operator=(const ClapTrap& other) {
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
	if (_energyPoints == 0)
		std::cout << "No more energy points!" << std::endl;
	else if (_hitPoints == 0)
		std::cout << _name << " is dead.." << std::endl;
	else {
		_energyPoints--;
		std::cout << _name << " attacks " << YLW << target << RST <<"! It's Super effective!" << std::endl;
	}
	std::cout << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount) {
	_hitPoints -= amount;
	std::cout << _name << RED << " took serious damage!" << RST << std::endl << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (_energyPoints == 0)
		std::cout << "No more energy points!" << std::endl;
	else if (_hitPoints == 0)
		std::cout << _name << " is dead.." << std::endl;
	else {
		_energyPoints--;
		_hitPoints += amount;
		if (_hitPoints > maxHitPoints)
			_hitPoints = maxHitPoints;
		std::cout << YLW << _name << RST << " repairs itself (" << GRN << "+" << amount << RST << ")!" << std::endl << std::endl;
	}
}

std::string		ClapTrap::getName(void) const {
	return (_name);
}

unsigned int	ClapTrap::getHitPoints(void) const {
	return (_hitPoints);
}

unsigned int	ClapTrap::getEnergyPoints(void) const {
	return (_energyPoints);
}