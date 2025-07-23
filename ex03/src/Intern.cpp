#include "../inc/Intern.hpp"
#include "../inc/AForm.hpp"

/****************************************************
*					CONSTRUCTORS					*
****************************************************/

Intern::Intern() {
	std::cout << "An " << color("intern", YLW) << " has been " << color("created", GRN) << "!" << std::endl; 
}

Intern::Intern(const Intern& other) {
	std::cout << "An " << color("intern", YLW) << " has been " << color("created", GRN) << "!" << std::endl; 
}

Intern::~Intern() {
	std::cout << color("Intern", YLW) << color(" destructor", RED) << " called!" << std::endl;
}

/****************************************************
*					OPERATORS						*
****************************************************/

Intern&	Intern::operator=(const Intern& other) {
	if (this != &other){
		*this = other;
	}
	return (*this);
}

/****************************************************
*					FUNCTIONS						*
****************************************************/

AForm*	Intern::makeForm(std::string name, std::string target) const {
	std::string forms[3] = {"PresidentialPardonForm", "RobotomyRequestForm", "ShrubberyCreationForm"};
	AForm	*(*new_forms[3])(std::string) = {
		&PresidentialPardonForm::newPresidential,
		&RobotomyRequestForm::newRobotomy,
		&ShrubberyCreationForm::newShrubbery
	};
}