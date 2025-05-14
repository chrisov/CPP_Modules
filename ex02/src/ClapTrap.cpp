#include <iostream>

#include "../inc/ClapTrap.hpp"

/****************************************************
*					CONSTRUCTORS					*
****************************************************/

ClapTrap::ClapTrap() {
	std::cout << YLW << "Default "<< RST << "constructor called" << std::endl;
	this->_name = "Default";
	this->_hitPoints = 10;
	this->_energyPoints = 10;
	this->_attackDamage = 0;
}

ClapTrap::ClapTrap(std::string name) {
	std::cout << "Parameterized constructor " << GRN << "created" << RST << " a ClapTrap named " << YLW << name << RST << std::endl;
	this->_name = name;
	this->_hitPoints = 10;
	this->_energyPoints = 10;
	this->_attackDamage = 0;
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
		this->_name = other._name;
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
	}
	return (*this);
}

std::ostream&	operator<<(std::ostream& out, const ClapTrap& obj) {
	const unsigned int maxHitPoints = 10;
	const unsigned int maxEnergyPoints = 10;
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

void	ClapTrap::attack(const std::string& target) {
	(void)target;
	if (this->_energyPoints == 0)
		std::cout << "No more energy points!" << std::endl;
	else if (this->_hitPoints == 0)
		std::cout << this->_name << " is dead.." << std::endl;
	else {
		this->_energyPoints--;
		std::cout << YLW << this->_name << RST << " attacks... ";
		if (this->_attackDamage == 0)
			std::cout << "It has no effect..." << std::endl;
		else if (this->_attackDamage == 20)
			std::cout << "It's not very effective." << std::endl;
		else 
			std::cout << "It's super effective!" << std::endl;
	}
}

void	ClapTrap::takeDamage(unsigned int amount) {
	if (amount <= this->_hitPoints)
		this->_hitPoints -= amount;
	else
		this->_hitPoints = 0;
	if (amount > 0)
		std::cout << YLW << this->_name << RED << " took some damage!" << RST << std::endl;
	if (this->_hitPoints == 0)
		std::cout << YLW << this->_name << RED << " died..." << RST << std::endl;
	std::cout << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (this->_energyPoints == 0)
		std::cout << "No more energy points!" << std::endl;
	else if (this->_hitPoints == 0)
		std::cout << this->_name << " is dead.." << std::endl;
	else {
		this->_energyPoints--;
		this->_hitPoints += amount;
		std::cout << YLW << this->_name << RST << " repairs itself!" << std::endl;
		std::cout << std::endl;
	}
}

unsigned int	ClapTrap::getAttackDmg(void) const {
	return (_attackDamage);
}

std::string		ClapTrap::getName(void) const {
	return (_name);
}