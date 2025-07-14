#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"
#include "Colors.hpp"

class Ice : public AMateria {

	public:
		Ice();
		Ice(const Ice& other);
		~Ice();

		Ice&	operator=(const Ice& other);

		AMateria*	clone(void) const override;
};

#endif
