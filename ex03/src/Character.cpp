#include "../inc/Character.hpp"

/****************************************************
*					CONSTRUCTORS					*
****************************************************/

ICharacter::ICharacter() : _name("Default") {
	for (int i = 0; i < 4; i++)
		_inv[i] = nullptr;
	std::cout << "Default " << color("constructor", GRN) << "created a " << color("character", YLW) << "!" << std::endl;
}

// todo: replace shallow -> deep copy
ICharacter::ICharacter(const ICharacter& other) : _name(other._name) {
	for (int i = 0; i < 4; i++)
		_inv[i] = other._inv[i];
	std::cout << "Copy " << color("constructor ", GRN) << "made a copy of the " << color(_name, YLW) << " character!" << std::endl;
}

ICharacter::ICharacter(const std::string& name) : _name(name) {
	for (int i = 0; i < 4; i++)
		_inv[i] = nullptr;
	std::cout << "Parameterized " << color("constructor", GRN) << "created a " << color("character", YLW) << "!" << std::endl;
}

ICharacter::~ICharacter() {
	std::cout << color(_name, YLW) << " was " << color("destroyed", RED) << "!" << std::endl;
}

/****************************************************
*					OPERATORS						*
****************************************************/

// todo: replace shallow -> deep copy
ICharacter&	ICharacter::operator=(const ICharacter& other) {
	if (this != &other) {
		_name = other._name;
		for (int i = 0; i < 4; i++)
			_inv[i] = other._inv[i];
	}
	return (*this);
}
