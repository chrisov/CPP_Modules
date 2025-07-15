#include "../inc/MateriaSource.hpp"

/****************************************************
*					CONSTRUCTORS					*
****************************************************/

MateriaSource::MateriaSource() {
	for (int i = 0; i < 4; i++)
		_inv[i] = nullptr;
	std::cout << "Default " << color("constructor ", GRN) << "created a new " << color("material source", YLW) << "!" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource& other) {
	for (int i = 0; i < 4; i++) {
		if (other._inv[i])
			_inv[i] = other._inv[i]->clone();
		else
			_inv[i] = nullptr;
	}
	std::cout << "Copy " << color("constructor ", GRN) << "created a copy of the " << color("material source", YLW) << "!" << std::endl;
}

MateriaSource::~MateriaSource() {
	for (int i = 0; i < 4; i++) {
		if (_inv[i])
			delete _inv[i];
	}
	std::cout << color("MateriaSource", YLW) << " was " << color("destroyed", RED) << "!" << std::endl;
}

/****************************************************
*					OPERATORS						*
****************************************************/

MateriaSource&	MateriaSource::operator=(const MateriaSource& other) {
	if (this != &other) {
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

void	MateriaSource::learnMateria(AMateria* newMateria) {
	for (int i = 0; i < 4; i++) {
		if (_inv[i] == nullptr) {
			std::cout << "New material " << color(newMateria->getType(), YLW) << color("learned", GRN) << "!" << std::endl;
			return ((void)(_inv[i] = newMateria->clone()));
		}
	}
	std::cout << color("MateriaSource", YLW) << color("full", GRN) << "!" << std::endl;
}

AMateria*	MateriaSource::createMateria(const std::string& type) {
	AMateria*	res;

	if (type == "ice" || type == "cure")
		return (res->clone());
	else
		return (0);
}