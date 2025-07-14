#include "../inc/Cure.hpp"

/****************************************************
*					CONSTRUCTORS					*
****************************************************/

Cure::Cure() : AMateria("ice") {
	std::cout << "Default " << color("constructor", GRN) << " turned Material into a " << color(_type, YLW) << std::endl;
}

Cure::Cure(const Cure& other) : AMateria(other) {
	std::cout << "Copy " << color("constructor ", GRN) << "made a copy of the " << color(_type, YLW) << " material!" << std::endl;
}

Cure::~Cure() {
	std::cout << color(_type, YLW) << " was " << color("destroyed", RED) << "!" << std::endl;
}

/****************************************************
*					OPERATORS						*
****************************************************/

Cure&	Cure::operator=(const Cure& other) {
	if (this != &other)
		_type = other._type;
	return (*this);
}

/****************************************************
*					FUNCTIONS						*
****************************************************/

AMateria*	Cure::clone(void) const {
	AMateria*	newCure = new Cure();
	return (newCure);
}