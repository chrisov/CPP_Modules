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
	std::cout << "Parameterized constructor " << GRN << "created " << RST << "ClapTrap named " << YLW << name << RST << std::endl;
	this->_name = name;
	this->_hitPoints = 10;
	this->_energyPoints = 10;
	this->_attackDamage = 0;
}

ClapTrap::ClapTrap(const ClapTrap& other) {
	*this = other;
}

ClapTrap::~ClapTrap() {
	std::cout << "Destructor called" << std::endl;
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
	int	filled = (obj._hitPoints * 20) / 10;
	int	empty = 20 - (obj._hitPoints * 20) / 10;
	
	out << YLW << obj._name << RST << " (Attack dmg: " << obj._attackDamage << ")" << std::endl;
	out << "Hit points: ";
	for (int i = 0; i < filled; ++i)
		out << GRN << "#" << RST;
	for (int i = 0; i < empty; ++i)
		out << GRN << "-" << RST;
	out << " (" << filled / 2 << "/" << "10)" << std::endl;
	out << "Energy points: ";
	filled = (obj._energyPoints * 20) / 10;
	empty = 20 - (obj._energyPoints * 20) / 10;
	for (int i = 0; i < filled; ++i)
		out << BLU << "#" << RST;
	for (int i = 0; i < empty; ++i)
		out << BLU << "-" << RST;
	out << "(" << filled / 2 << "/" << "10)" << std::endl << std::endl;
	return (out);
}

/****************************************************
*						FUNCTIONS					*
****************************************************/

void	ClapTrap::attack(const std::string& target) {
	if (this->_energyPoints == 0)
		std::cout << "No more energy points!" << std::endl;
	else if (this->_hitPoints == 0)
		std::cout << this->_name << " is dead.." << std::endl;
	else {
		this->_energyPoints--;
		std::cout << this->_name << " attacks! Super effective!" << std::endl;
		std::cout << "Energy points: " << this->_energyPoints << std::endl;
		std::cout << target << " lost " << this->_attackDamage << " hit points.." << std::endl;
	}
	std::cout << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount) {
	this->_hitPoints -= amount;
	std::cout << this->_name << RED << " took serious damage!" << RST << std::endl << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (this->_energyPoints == 0)
		std::cout << "No more energy points!" << std::endl;
	else if (this->_hitPoints == 0)
		std::cout << this->_name << " is dead.." << std::endl;
	else {
		this->_energyPoints--;
		this->_hitPoints += amount;
		std::cout << this->_name << " repairs itself!" << std::endl;
		std::cout << "Hit points: " << this->_hitPoints << std::endl;
		std::cout << "Energy points: " << this->_energyPoints << std::endl;
		std::cout << std::endl;
	}
}

unsigned int	ClapTrap::getAttackDmg(void) const {
	return (_attackDamage);
}

std::string		ClapTrap::getName(void) const {
	return (_name);
}