#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class AForm;

class Intern {
	public:
		Intern();
		Intern(const Intern& other);
		~Intern();

		Intern&	operator=(const Intern& other);

		AForm*	makeForm(std::string name, std::string target) const;
};

#endif