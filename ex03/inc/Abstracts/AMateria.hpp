#ifndef AMATERIAL_HPP
#define AMATERIAL_HPP

#include <iostream>

#include "Colors.hpp"
// #include "Interfaces/ICharacter.hpp"
class ICharacter;

class AMateria
{

	protected:
		std::string	_type;

	public:
		AMateria();
		AMateria(const std::string& type);
		AMateria(const AMateria& other);
		virtual ~AMateria(); 

		AMateria&	operator=(const AMateria& other);

		const std::string&	getType(void) const;
		virtual AMateria*	clone(void) const = 0;
		virtual void		use(ICharacter& target) = 0;
};

#endif