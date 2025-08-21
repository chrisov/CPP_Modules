#ifndef BRAIN_HPP
#define BRAIN_HPP

#define RST "\033[0m"
#define RED "\033[31m"
#define GRN "\033[32m"
#define YLW "\033[33m"

#include <iostream>

class Brain {
	
	public:
		std::string	ideas[100];

		Brain();
		Brain(const std::string& newidea);
		Brain(const Brain& other);
		~Brain();

		Brain&	operator=(const Brain& other);

		void	speakUp(void) const;
		void	changedMyMind(const std::string newidea);
};

#endif