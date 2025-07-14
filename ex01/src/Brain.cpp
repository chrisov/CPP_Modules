#include "../inc/Brain.hpp"

/****************************************************
*					CONSTRUCTORS					*
****************************************************/

Brain::Brain() {
	std::cout << "New empty " << YLW << "Brain " << GRN << "is created " << RST << std::endl;
	for (int i = 0; i < 100; i++)
	ideas[i] = "";
}

Brain::Brain(const std::string& newidea) {
	if (newidea.empty())
		std::cout << "New empty " << YLW << "Brain is " << GRN << "created " << RST << std::endl;
	else
		std::cout << "New " << YLW << "Brain is " << GRN << "created " << RST << "and filled with a specific idea!" << std::endl;
	for (int i = 0; i < 100; i++)
		ideas[i] = newidea;
}

Brain::Brain(const Brain& other) {
	std::cout << "New " << YLW << "Brain is " << GRN << "created " << RST << "and filled with copied ideas!" << std::endl;
	for (int i = 0; i < 100; i ++)
		ideas[i] = other.ideas[i];
}

Brain::~Brain() {
	std::cout << "This " << YLW << "brain " << RST << "was rot and got " << RED << "destroyed" << RST << "!" << std::endl;
}

/***************************************p*************
*					OPERATORS						*
****************************************************/

Brain&	Brain::operator=(const Brain& other) {
	if (this != &other) {
		for (int i = 0; i < 100; i++)
			ideas[i] = other.ideas[i];
	}
	return (*this);
}

/****************************************************
*					FUNCTIONS						*
****************************************************/

void	Brain::speakUp(void) const {
	std::cout << "\"I have so many great ideas\" (" << YLW << ideas[99] << RST << ")" << std::endl;
}

void	Brain::changedMyMind(const std::string newidea) {
	for (int i = 0; i < 100; i++) {
		ideas[i] = newidea;
	}
}