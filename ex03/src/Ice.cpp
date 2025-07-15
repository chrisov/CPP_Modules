#include "../inc/Ice.hpp"

/****************************************************
*					CONSTRUCTORS					*
****************************************************/

Ice::Ice() : AMateria("ice") {
	std::cout << "Default " << color("constructor", GRN) << " turned Material into a " << color(_type, YLW) << std::endl;
}

Ice::Ice(const Ice& other) : AMateria(other) {
	std::cout << "Copy " << color("constructor ", GRN) << "made a copy of the " << color(_type, YLW) << " material!" << std::endl;
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
	return (new Ice(*this));
}

void	Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at " << color(target.getName(), RED) << " *" << std::endl; 
}