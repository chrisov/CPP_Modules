#ifndef ICE_HPP
#define ICE_HPP

#include "Abstracts/AMateria.hpp"

class Ice : public AMateria {

	public:
		Ice();
		Ice(const Ice& other);
		~Ice();

		Ice&	operator=(const Ice& other);

		AMateria*	clone(void) const override;
		void		use(ICharacter& target) override;
};

#endif
