#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

#include "Brain.hpp"

#define RST "\033[0m"
#define RED "\033[31m"
#define GRN "\033[32m"
#define YLW "\033[33m"

class Animal {

	protected:
		std::string	type;
		Brain*		_brain;

	public:
		Animal();
		Animal(const Animal& other);
		virtual ~Animal();

		virtual void			makeSound(void) const;
		virtual std::string		getType(void) const;
};

#endif
