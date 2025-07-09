#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
	public:
		FragTrap();
		FragTrap(std::string name);
		FragTrap(const FragTrap& other);
		~FragTrap();

		FragTrap&	operator=(const FragTrap& other);

		void	attack(const std::string& target) override;
		void	highFiveGuys(void);
	};
	
std::ostream&	operator<<(std::ostream& out, const FragTrap& obj);

#endif
