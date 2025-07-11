#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include <iostream>
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
	
	private:
		std::string	type;

	public:
		WrongCat();
		WrongCat(const WrongCat& other);
		~WrongCat();

		void		makeSound(void) const override;
		std::string	getType(void) const override;
};

#endif