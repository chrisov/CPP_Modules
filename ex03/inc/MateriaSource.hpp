#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "Interfaces/IMateriaSource.hpp"

class AMateria;

class MateriaSource : public IMateriaSource {

	private:
		AMateria*	_src[4];

	public:
		MateriaSource();
		MateriaSource(const MateriaSource& other);
		~MateriaSource();

		MateriaSource& operator=(const MateriaSource& other);

		void		learnMateria(AMateria* newMateria) override;
		AMateria*	createMateria(const std::string& type) override;
		void		getSource(void) override;
};

#endif