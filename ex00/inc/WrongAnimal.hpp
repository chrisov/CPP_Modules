#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>

#define RST "\033[0m"
#define RED "\033[31m"
#define GRN "\033[32m"
#define YLW "\033[33m"

class WrongAnimal {

	protected:
		std::string	type;

	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal& other);
		WrongAnimal(const std::string& newtype);
		virtual ~WrongAnimal();

		WrongAnimal&	operator=(const WrongAnimal& other);

		virtual void	makeSound(void) const;
		std::string		getType(void) const;
};

#endif
