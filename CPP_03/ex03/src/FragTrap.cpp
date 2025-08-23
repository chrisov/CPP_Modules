#include "FragTrap.hpp"

/****************************************************
*					CONSTRUCTORS					*
****************************************************/

FragTrap::FragTrap() : ClapTrap("Default", _maxHitPoints, _maxEnergyPoints) {
	std::cout << "Default FragTrap constructor called" << std:: endl;
}

FragTrap::FragTrap(const std::string name) : ClapTrap(name, _maxHitPoints, _maxEnergyPoints){
	std::cout << "Parameterized constructor turned " << YLW << _name << RST << " into a FragTrap" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
	std::cout << "Copy constructor created another " << YLW << other._name << RST << " FragTrap instance" << std::endl;
}

FragTrap::~FragTrap() {
	std::cout << YLW << _name << RST << " FragTrap "<< RED << "destructor " << RST << "called" << std::endl;
}

/****************************************************
*						OPERATORS					*
****************************************************/

FragTrap&	FragTrap::operator=(const FragTrap& other) {
	if (this != &other) {
		_name = other._name;
		_hitPoints = other._hitPoints;
		_energyPoints = other._energyPoints;
	}
	return (*this);
}

std::ostream&	operator<<(std::ostream& out, const FragTrap& obj) {
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

void	FragTrap::highFiveGuys(void) {
	std::cout << YLW << _name << RST << " requests the highest of the fives!" << std::endl;
}

void	FragTrap::attack(const std::string& target) {
	(void)target;
	if (_energyPoints == 0)
		std::cout << "No more energy points!" << std::endl;
	else if (_hitPoints == 0)
		std::cout << YLW << _name << RST << " is " << RED << "dead" << RST << "..." << std::endl;
	else {
		_energyPoints--;
		std::cout << "FragTrap " << YLW << _name << RST << " attacks... ";
		std::cout << "It's super effective!" << std::endl;
	}
}

unsigned int	FragTrap::getAttackDmg(void) const {
	return (_attackDamage);
}

unsigned int	FragTrap::getMaxHP(void) const {
	return (_maxHitPoints);
}

unsigned int	FragTrap::getMaxEP(void) const {
	return (_maxEnergyPoints);
}