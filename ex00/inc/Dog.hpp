#ifndef DOG_HPP
#define DOG_HPP

#include <iostream>
#include "Animal.hpp"

class Dog : public Animal {
	private:
		std::string	type;

	public:
		Dog();
		Dog(const Dog& other);
		~Dog();

		void		makeSound(void) const override;
		std::string	getType(void) const override;
};

#endif
