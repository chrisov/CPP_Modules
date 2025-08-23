#ifndef CAT_HPP
#define CAT_HPP

#include <iostream>
#include "Animal.hpp"

class Cat : public A_Animal {
	
	public:
		Cat();
		Cat(const Cat& other);
		Cat(const std::string& newidea);
		~Cat();

		Cat&	operator=(const Cat& other);

		void	makeSound(void) const override;
};

#endif