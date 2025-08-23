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
		Animal(const Animal& other);
		Animal(const std::string& newidea, const std::string& newtype);
		virtual ~Animal();

		Animal&	operator=(const Animal& other);

		virtual void	makeSound(void) const;
		std::string		getType(void) const;
		Brain*			getBrain(void) const;
};

#endif
