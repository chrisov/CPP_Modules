#ifndef CURE_HPP
#define CURE_HPP

#include "Abstracts/AMateria.hpp"

class Cure : public AMateria {

	public:
		Cure();
		Cure(const Cure& other);
		~Cure();

		Cure&	operator=(const Cure& other);

		AMateria*	clone(void) const override;
		void		use(ICharacter& target) override;
};

#endif
