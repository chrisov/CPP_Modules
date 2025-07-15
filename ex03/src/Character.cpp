#include "../inc/Character.hpp"

/****************************************************
*					CONSTRUCTORS					*
****************************************************/

Character::Character() : _name("Default") {
	for (int i = 0; i < 4; i++)
		_inv[i] = nullptr;
	std::cout << "Default " << color("constructor", GRN) << "created a character named " << color(_name, YLW) << "!" << std::endl;
}

Character::Character(const Character& other) : _name(other._name) {
	for (int i = 0; i < 4; i++) {
		if (other._inv[i])
			_inv[i] = other._inv[i]->clone();
		else
			_inv[i] = nullptr;
	}
	std::cout << "Copy " << color("constructor ", GRN) << "made a copy of the " << color(_name, YLW) << " character!" << std::endl;
}

Character::Character(const std::string& name) : _name(name) {
	for (int i = 0; i < 4; i++)
		_inv[i] = nullptr;
	std::cout << "Parameterized " << color("constructor", GRN) << "created a " << color("character", YLW) << "!" << std::endl;
}

Character::~Character() {
	for (int i = 0; i < 4; i++) {
		if (_inv[i])
			delete _inv[4];
	}
	std::cout << color(_name, YLW) << " was " << color("destroyed", RED) << "!" << std::endl;
}

/****************************************************
*					OPERATORS						*
****************************************************/

Character&	Character::operator=(const Character& other) {
	if (this != &other) {
		_name = other._name;
		for (int i = 0; i < 4; i++) {
			delete _inv[i];
			if (other._inv[i])
				_inv[i] = other._inv[i]->clone();
			else
				_inv[i] = nullptr;
		}
	}
	return (*this);
}

/****************************************************
*					FUNCTIONS						*
****************************************************/

const std::string&	Character::getName(void) const {
	return (_name);
}

void	Character::equip(AMateria* m) {
	for (int i = 0; i < 4; i++) {
		if (_inv[i] == nullptr) {
			std::cout << color(m->getType(), YLW) << color(" added ", GRN) << "to the inventory!" << std::endl;
			return ((void)(_inv[i] = m));
		}
	}
	std::cout << color("Inventory ", YLW) << color("full", RED) << "!" << std::endl;
}

void	Character::unequip(int idx) {
	_inv[idx] == nullptr;
}

void	Character::use(int idx, ICharacter& target) {
	_inv[idx]->use(target);
}