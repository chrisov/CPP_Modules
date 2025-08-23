#include "../inc/MateriaSource.hpp"

/****************************************************
*					CONSTRUCTORS					*
****************************************************/

MateriaSource::MateriaSource() {
	for (int i = 0; i < 4; i++)
		_src[i] = nullptr;
	std::cout << "Default " << color("constructor ", GRN) << "created a new " << color("MateriaSource", YLW) << "!" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource& other) {
	for (int i = 0; i < 4; i++) {
		if (other._src[i])
			_src[i] = other._src[i]->clone();
		else
			_src[i] = nullptr;
	}
	std::cout << "Copy " << color("constructor ", GRN) << "created a copy of the " << color("Materia source", YLW) << "!" << std::endl;
}

MateriaSource::~MateriaSource() {
	for (int i = 0; i < 4; i++) {
		if (_src[i])
			delete _src[i];
	}
	std::cout << color("MateriaSource", YLW) << " was " << color("destroyed", RED) << "!" << std::endl;
}

/****************************************************
*					OPERATORS						*
****************************************************/

MateriaSource&	MateriaSource::operator=(const MateriaSource& other) {
	if (this != &other) {
		for (int i = 0; i < 4; i++) {
			delete _src[i];
			if (other._src[i])
				_src[i] = other._src[i]->clone();
			else
				_src[i] = nullptr;
		}
	}
	return (*this);
}

/****************************************************
*					FUNCTIONS						*
****************************************************/

void	MateriaSource::getSource(void) {
	std::cout << std::endl;
	for (int i = 0; i < 4; i++) {
		std::cout << color("Materia", YLW) << " no." << std::to_string(i) << " (" << _src[i] << "): '";
		if (_src[i])
			std::cout << color(_src[i]->getType(), YLW);
		std::cout << "'" << std::endl;
	}
}

void	MateriaSource::learnMateria(AMateria* newMateria) {
	for (int i = 0; i < 4; i++) {
		if (_src[i] == nullptr) {
			std::cout << "New materia " << color(newMateria->getType(), YLW) << color(" learned", GRN) << "!" << std::endl;
			return ((void)(_src[i] = newMateria->clone()));
		}
	}
	std::cout << color("MateriaSource ", YLW) << color("full", GRN) << "!" << std::endl;
}

AMateria*	MateriaSource::createMateria(const std::string& type) {
	for (int i = 0; i < 4; ++i) {
		if (_src[i] && _src[i]->getType() == type) {
			return _src[i]->clone();
		}
	}
	return nullptr;
}