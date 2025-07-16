#include "../inc/Cure.hpp"

/****************************************************
*					CONSTRUCTORS					*
****************************************************/

Cure::Cure() : AMateria("cure") {
	std::cout << "Default " << color("constructor", GRN) << " turned Materia into a " << color(_type, YLW) << std::endl;
}

Cure::Cure(const Cure& other) : AMateria(other) {
	std::cout << "Copy " << color("constructor ", GRN) << "made a copy of the " << color(_type, YLW) << " Materia!" << std::endl;
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
	std::cout << "New " << color(getType(), YLW) << " Materia is " << color("created", GRN) << "!" << std::endl;
	return (new Cure(*this));
}

void	Cure::use(ICharacter& target) {
	std::cout << "* " << color("heals ", GRN) << color(target.getName(), YLW) << "'s wounds *" << std::endl;
}