#ifndef DOG_HPP
#define DOG_HPP

#include <iostream>
#include "Animal.hpp"

class Dog : public A_Animal {

	public:
		Dog();
		Dog(const std::string& newidea);
		Dog(const Dog& other);
		~Dog();

		Dog&	operator=(const Dog& other);

		void	makeSound(void) const override;
};

#endif
