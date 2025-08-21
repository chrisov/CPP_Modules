#include "../inc/Ice.hpp"

/****************************************************
*					CONSTRUCTORS					*
****************************************************/

Ice::Ice() : AMateria("ice") {
	std::cout << "Default " << color("constructor", GRN) << " turned Materia into " << color(_type, YLW) << "!" << std::endl;
}

Ice::Ice(const Ice& other) : AMateria(other) {
	std::cout << "Copy " << color("constructor ", GRN) << "made a copy of the " << color(_type, YLW) << " Materia!" << std::endl;
}

Ice::~Ice() {
	std::cout << color(_type, YLW) << " was " << color("destroyed", RED) << "!" << std::endl;
}

/****************************************************
*					OPERATORS						*
****************************************************/

Ice&	Ice::operator=(const Ice& other) {
	if (this != &other)
		_type = other._type;
	return (*this);
}

/****************************************************
*					FUNCTIONS						*
****************************************************/

AMateria*	Ice::clone(void) const {
	std::cout << "New " << color(getType(), YLW) << " Materia is " << color("created", GRN) << "!" << std::endl;
	return (new Ice(*this));
}

void	Ice::use(ICharacter& target) {
	std::cout << "* " << color("shoots", RED) << " an ice bolt at " << color(target.getName(), YLW) << " *" << std::endl; 
}