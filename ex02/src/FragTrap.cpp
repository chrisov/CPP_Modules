#include "../inc/FragTrap.hpp"

/****************************************************
*					CONSTRUCTORS					*
****************************************************/

FragTrap::FragTrap() {
	std::cout << "Default FragTrap constructor called" << std:: endl;
	_hitPoints = maxHitPoints;
	_energyPoints = maxEnergyPoints;
}

FragTrap::FragTrap(const std::string name) : ClapTrap(name) {
	std::cout << "Parameterized constructor turned " << YLW << name << RST << " into a FragTrap" << std::endl;
	_hitPoints = maxHitPoints;
	_energyPoints = maxEnergyPoints;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
	std::cout << "Copy constructor created another " << YLW << other._name << RST << " FragTrap instance" << std::endl;
	*this = other;
}

FragTrap::~FragTrap() {
	std::cout << YLW << _name << RST << " FragTrap "<< RED << "destructor " << RST << "called" << std::endl;
}

/****************************************************
*						OPERATORS					*
****************************************************/

FragTrap&	FragTrap::operator=(const FragTrap& other) {
	if (this != &other) {
		this->_name = other._name;
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
	}
	return (*this);
}

std::ostream&	operator<<(std::ostream& out, const FragTrap& obj) {
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

void	FragTrap::highFiveGuys(void) {
	std::cout << YLW << _name << RST << " request the highest of the fives!" << std::endl;
}

void	FragTrap::attack(const std::string& target) {
	(void)target;
	if (_energyPoints == 0)
		std::cout << "No more energy points!" << std::endl;
	else if (_hitPoints == 0)
		std::cout << "FragTrap " << _name << " is dead.." << std::endl;
	else {
		_energyPoints--;
		std::cout << YLW << _name << RST << " attacks... ";
	}
}
