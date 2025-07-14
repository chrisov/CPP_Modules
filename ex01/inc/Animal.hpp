#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#define RST "\033[0m"
#define RED "\033[31m"
#define GRN "\033[32m"
#define YLW "\033[33m"

#include <iostream>
#include "Brain.hpp"

class Animal {

	protected:
		Brain*		_brain;
		std::string	type;

	public:
		Animal();
		Animal(const std::string idea);
		Animal(const Animal& other);
		virtual ~Animal();

		Animal&	operator=(const Animal& other);

		virtual void			makeSound(void) const;
		virtual std::string		getType(void) const;
		Brain*					getBrain(void) const;
};

#endif
