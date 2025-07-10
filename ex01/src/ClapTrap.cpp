#include "../inc/ClapTrap.hpp"

/****************************************************
*					CONSTRUCTORS					*
****************************************************/

ClapTrap::ClapTrap() :
	_name("Default"),
	_hitPoints(_maxHitPoints),
	_energyPoints(_maxEnergyPoints) {
		std::cout << YLW << "Default "<< RST << "constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) :
	_name(name),
	_hitPoints(_maxHitPoints),
	_energyPoints(_maxEnergyPoints) {
		std::cout << "Parameterized default constructor " << GRN << "created" << RST << " a ClapTrap named " << YLW << name << RST << std::endl;
}

ClapTrap::ClapTrap(std::string name, unsigned int HP, unsigned int EP) :
	_name(name),
	_hitPoints(HP),
	_energyPoints(EP) {
		std::cout << "Parameterized constructor " << GRN << "created" << RST << " a ClapTrap named " << YLW << name << RST << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) :
	_name(other._name),
	_hitPoints(other._hitPoints),
	_energyPoints(other._energyPoints) {
		std::cout << "Copy constructor " << GRN << "created" << RST << " a ClapTrap named " << YLW << other._name << RST << std::endl;
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
	(void)target;
	if (_energyPoints == 0)
		std::cout << "No more energy points!" << std::endl;
	else if (_hitPoints == 0)
		std::cout << YLW << _name << RST << " is " << RED << "dead" << RST << "..." << std::endl;
	else {
		_energyPoints--;
		std::cout << "ClapTrap " << YLW << _name << RST << " attacks... ";
		std::cout << "It has no effect..." << std::endl;
	}
}

void	ClapTrap::takeDamage(unsigned int amount) {
	if (amount <= _hitPoints)
		_hitPoints -= amount;
	else
		std::cout << YLW << _name << RED << " took some damage" << RST << "!" << std::endl;
	if (amount <= _hitPoints)
		_hitPoints -= amount;
	else
		_hitPoints = 0;
	if (_hitPoints == 0)
		std::cout << YLW << _name << RED << " died" << RST << "..." << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (_energyPoints == 0)
		std::cout << "No more energy points!" << std::endl;
	else if (_hitPoints == 0)
		std::cout << YLW << _name << RST << " can't repair itselft, it's " << RED << "dead" << RST << "..." << std::endl;
	else {
		_energyPoints--;
		_hitPoints += amount;
		if (_hitPoints >= getMaxHP())
			_hitPoints = getMaxHP();
		std::cout << YLW << _name << RST << " repairs itself!" << " (" << GRN << "+" << amount << RST << ")";
		std::cout << std::endl;
	}
}

unsigned int	ClapTrap::getAttackDmg(void) const {
	return (_attackDamage);
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

unsigned int	ClapTrap::getMaxHP(void) const {
	return (_maxHitPoints);
}

unsigned int	ClapTrap::getMaxEP(void) const {
	return (_maxEnergyPoints);
}