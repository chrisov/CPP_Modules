#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#define RST "\033[0m"
#define RED "\033[31m"
#define GRN "\033[32m"
#define YLW "\033[33m"

#include <iostream>
#include "Brain.hpp"

class A_Animal {

	protected:
		Brain*		_brain;
		std::string	type;

	public:
		A_Animal();
		A_Animal(const A_Animal& other);
		A_Animal(const std::string& newidea, const std::string& newtype);
		virtual ~A_Animal();

		A_Animal&	operator=(const A_Animal& other);

		virtual void	makeSound(void) const = 0;
		std::string		getType(void) const;
		Brain*			getBrain(void) const;
};

#endif
