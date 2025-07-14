#ifndef CURE_HPP
#define CURE_HPP

#include "../inc/AMateria.hpp"
#include "../inc/Colors.hpp"

class Cure : public AMateria {

	public:
		Cure();
		Cure(const Cure& other);
		~Cure();

		Cure&	operator=(const Cure& other);

		AMateria*	clone(void) const override;
};

#endif
