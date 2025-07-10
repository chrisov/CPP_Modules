#include "DiamondTrap.hpp"

const unsigned int	DiamondTrap::_attackDamage = FragTrap::_attackDamage;
const unsigned int	DiamondTrap::_maxHitPoints = FragTrap::_maxHitPoints;
const unsigned int	DiamondTrap::_maxEnergyPoints = ScavTrap::_maxEnergyPoints;

/****************************************************
*					CONSTRUCTORS					*
****************************************************/

DiamondTrap::DiamondTrap() :
	ClapTrap("Default_clap_name"),
	ScavTrap(),
	FragTrap(),
	_name("Default") {
		std::cout << "Default DiamondTrap constructor called" << std::endl;
		_hitPoints = getMaxHP();
		_energyPoints = getMaxEP();
}

DiamondTrap::DiamondTrap(std::string name) :
	ClapTrap(name + "_clap_name"),
	ScavTrap(name),
	FragTrap(name),
	_name(name) {
		std::cout << "Parameterized constructor turned " << YLW << _name << RST << " into a DiamondTrap" << std::endl;
		_hitPoints = getMaxHP();
		_energyPoints = getMaxEP();
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) : ClapTrap(other) {
	std::cout << "Copy constructor created another " << YLW << other._name << RST << " DiamondTrap instance" << std::endl;
}

DiamondTrap::~DiamondTrap() {
	std::cout << YLW << _name << RST << " DiamondTrap "<< RED << "destructor " << RST << "called" << std::endl;
}

/****************************************************
*					OPERATORS						*
****************************************************/

DiamondTrap&	DiamondTrap::operator=(const DiamondTrap& other) {
	if (this != &other) {
		_name = other._name;
		_hitPoints = other._hitPoints;
		_energyPoints = other._energyPoints;
	}
	return (*this);
}

std::ostream&	operator<<(std::ostream& out, const DiamondTrap& obj) {
	const unsigned int barLength = 20;

	int filledHealth = (obj.getHitPoints() > 0) ? (obj.getHitPoints() * barLength) / obj.getMaxHP() : 0;
	int emptyHealth = barLength - filledHealth;
	int filledEnergy = (obj.getEnergyPoints() > 0) ? (obj.getEnergyPoints() * barLength) / obj.getMaxEP() : 0;
	int emptyEnergy = barLength - filledEnergy;

	out << YLW << obj.getName() << RST << " (" << YLW << obj.ClapTrap::getName() << RST << ") (Attack dmg: " << obj.getAttackDmg() << ")" << std::endl;

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
*					FUNCTIONS						*
****************************************************/

void	DiamondTrap::whoAmI(void) {
	std::cout << "Clap name: " << ClapTrap::_name << "\nName: " << _name << std::endl; 
}

std::string	DiamondTrap::getName(void) const {
	return (_name);
}

void	DiamondTrap::attack(const std::string& target) {
	ScavTrap::attack(target);
}

unsigned int	DiamondTrap::getAttackDmg(void) const {
	return (ScavTrap::getAttackDmg());
}

unsigned int	DiamondTrap::getMaxHP(void) const {
	return (_maxHitPoints);
}

unsigned int	DiamondTrap::getMaxEP(void) const {
	return (_maxEnergyPoints);
}