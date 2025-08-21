#include "../../inc/Abstracts/AMateria.hpp"

/****************************************************
*					CONSTRUCTORS					*
****************************************************/

AMateria::AMateria() : _type("Default") {
	std::cout << "Default " << color("constructor ", GRN) << "created a " << color(_type, YLW) << " Materia!" << std::endl;
}

AMateria::AMateria(const std::string& type) : _type(type) {
	std::cout << "Parameterized Materia " << color("constructor", GRN) << " will call the " << color(type, YLW) << " constructor!" << std::endl;
}

AMateria::AMateria(const AMateria& other) : _type(other._type) {
	std::cout << "Materia copy " << color("constructor", GRN) << " will call the " << color(_type, YLW) << " copy constructor!" << std::endl;
}

AMateria::~AMateria() {
	std::cout << color("Materia", YLW) << color(" destructor", RED) << " is called!" << std::endl;
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
