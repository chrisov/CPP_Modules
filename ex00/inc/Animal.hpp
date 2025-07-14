#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

#define RST "\033[0m"
#define RED "\033[31m"
#define GRN "\033[32m"
#define YLW "\033[33m"

class Animal {

	protected:
		std::string	type;

	public:
		Animal();
		Animal(const Animal& other);
		Animal(const std::string& newtype);
		virtual ~Animal();

		Animal&	operator=(const Animal& other);

		virtual void			makeSound(void) const;
		virtual std::string		getType(void) const;
};

#endif
