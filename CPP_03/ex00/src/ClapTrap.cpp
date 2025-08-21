#include "../inc/ClapTrap.hpp"

/****************************************************
*					CONSTRUCTORS					*
****************************************************/

ClapTrap::ClapTrap() : _name("Default"), _hitPoints(_maxHitPoints), _energyPoints(_maxEnergyPoints) {
	std::cout << YLW << "Default "<< RST << "constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(_maxHitPoints), _energyPoints(_maxEnergyPoints) {
	std::cout << "Parameterized constructor " << GRN << "created " << RST << "ClapTrap named " << YLW << name << RST << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) {
	std::cout << "Copy constructor called on the " << YLW << other._name << RST << " instance" << std::endl;
	*this = other;
}

ClapTrap::~ClapTrap() {
	std::cout << RED << "Destructor " << RST << "called" << std::endl;
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

	int filledHealth = (obj.getHitPoints() > 0) ? (obj.getHitPoints() * barLength) / obj.getMaxHP() : 0;
    int emptyHealth = barLength - filledHealth;
    int filledEnergy = (obj.getEnergyPoints() > 0) ? (obj.getEnergyPoints() * barLength) / obj.getMaxEP() : 0;
    int emptyEnergy = barLength - filledEnergy;

	out << YLW << obj.getName() << RST << " (Attack dmg: " << obj.getAttackDmg() << ")" << std::endl;

	out << "Hit points: ";
	for (int i = 0; i < filledHealth; ++i)
		out << GRN << "#" << RST;
	for (int i = 0; i < emptyHealth; ++i)
		out << GRN << "-" << RST;
	out << " (" << obj.getHitPoints() << "/" << obj.getMaxHP() << ")" << std::endl;

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

void	ClapTrap::attack(const std::string& target) {
	if (_energyPoints == 0)
		std::cout << "No more energy points!" << std::endl;
	else if (_hitPoints == 0)
		std::cout << YLW << _name << RST << " is " << RED << "dead.." << RST << std::endl;
	else {
		_energyPoints--;
		std::cout << YLW << _name << RST << " attacks " << YLW << target << RST <<"!" << std::endl;
	}
}

void	ClapTrap::takeDamage(unsigned int amount) {
	if (amount == 0)
		std::cout << YLW << _name << RED << " took no damage!" << RST << std::endl;
	else {
		_hitPoints -= amount;
		std::cout << YLW << _name << RED << " took some damage!" << RST << std::endl;
	}
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (_energyPoints == 0)
		std::cout << "No more energy points!" << std::endl;
	else if (_hitPoints == 0)
		std::cout << YLW << _name << " is " << RED << "dead.." << RST << std::endl;
	else {
		_energyPoints--;
		_hitPoints += amount;
		if (_hitPoints > _maxHitPoints)
			_hitPoints = _maxHitPoints;
		std::cout << YLW << _name << RST << " repairs itself (" << GRN << "+" << amount << RST << ")!" << std::endl;
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

unsigned int	ClapTrap::getMaxHP(void) const {
	return (_maxHitPoints);
}

unsigned int	ClapTrap::getMaxEP(void) const {
	return (_maxEnergyPoints);
}

unsigned int	ClapTrap::getAttackDmg(void) const {
	return (_attackDamage);
}