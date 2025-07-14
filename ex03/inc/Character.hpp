#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>

#include "Colors.hpp"

class ICharacter {
	
	private:
		std::string	_name;
		AMateria*	_inv[4];

	public:
		ICharacter();
		ICharacter(const ICharacter& other);
		ICharacter(const std::string& name);
		virtual ~ICharacter();

		ICharacter&	operator=(const ICharacter& other);
		
		virtual const std::string&	getName() const = 0;
		virtual void				equip(AMateria* m) = 0;
		virtual void				unequip(int idx) = 0;
		virtual void				use(int idx, ICharacter& target) = 0;
};

#endif