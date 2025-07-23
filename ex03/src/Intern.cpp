#include "../inc/Intern.hpp"
#include "../inc/AForm.hpp"

/****************************************************
*					CONSTRUCTORS					*
****************************************************/

Intern::Intern() {
	std::cout << "An " << color("intern", YLW) << " has been " << color("created", GRN) << "!" << std::endl; 
}

Intern::Intern(const Intern& other) {
	*this = other;
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

AForm*	Intern::makeForm(std::string name, std::string target) {
	std::string forms[3] = {"PresidentialPardonForm", "RobotomyRequestForm", "ShrubberyCreationForm"};
	AForm	*(*new_forms[3])(std::string) = {
		&PresidentialPardonForm::newPresidential,
		&RobotomyRequestForm::newRobotomy,
		&ShrubberyCreationForm::newShrubbery
	};
	for (int i = 0; i < 3; i++) {
		if (name.compare(forms[i]) == 0) {
			std::cout << color("Intern", YLW) << color(" creates ", GRN) << forms[i] << "!" << std::endl;
			return ((new_forms[i])(target));
		}
	}
	std::cout << color("Intern ", YLW) << color("failed", RED) << " to create '" << color(name, YLW) << "' form!" << std::endl;
	return (0);
}