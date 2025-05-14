#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>

class FragTrap : public ClapTrap {
	public:
		FragTrap();
		FragTrap(const FragTrap& other);
		FragTrap(std::string name);
		~FragTrap();

		FragTrap&	operator=(const FragTrap& other);

		friend std::ostream& operator<<(std::ostream& out, const FragTrap& obj);

		void	highFiveGuys(void);
};

#endif
