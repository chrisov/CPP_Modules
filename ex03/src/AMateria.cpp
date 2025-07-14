#include "../inc/AMateria.hpp"

/****************************************************
*					CONSTRUCTORS					*
****************************************************/

AMateria::AMateria() : _type("Default") {
	std::cout << "Default " << color("constructor ", GRN) << "created a " << color(_type, YLW) << " material!" << std::endl;
}

AMateria::AMateria(const std::string& type) : _type(type) {
	std::cout << "Parameterized " << color("constructor ", GRN) << "created a " << color(type, YLW) << " material!" << std::endl;
}

AMateria::AMateria(const AMateria& other) : _type(other._type) {
	std::cout << "Copy " << color("constructor ", GRN) << "made a copy of the " << color(_type, YLW) << "!" << std::endl;
}

AMateria::~AMateria() {
	std::cout << color(_type, YLW) << " was " << color("destroyed", RED) << "!" << std::endl;
}

/****************************************************
*						OPERATORS					*
****************************************************/

AMateria&	AMateria::operator=(const AMateria& other) {
	if (this != &other)
		_type = other._type;
	return (*this);
}

/****************************************************
*						FUNCTIONS					*
****************************************************/

const std::string&	AMateria::getType(void) const {
	return(_type);
}