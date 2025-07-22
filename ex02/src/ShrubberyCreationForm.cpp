#include "../inc/ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

/****************************************************
*					CONSTRUCTORS					*
****************************************************/

ShrubberyCreationForm::ShrubberyCreationForm() : AForm::AForm("Default", _minSignGrade, _minExecGrade) {
	std::cout << "Shrubbery '" << color(getName(), YLW) << "' is " << color("created", GRN) << "!" << std::endl;	
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string name) : AForm::AForm(name, _minSignGrade, _minExecGrade) {
	std::cout << "Shrubbery '" << color(getName(), YLW) << "' is " << color("created", GRN) << "!" << std::endl;	
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm::AForm(other) {
	std::cout << "Shrubbery '" << color(getName(), YLW) << "' is " << color("created", GRN) << "!" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "SCF '" << color(getName(), YLW) << "' is " << color("destroyed", RED) << "!" << std::endl;
}

/****************************************************
*					OPERATORS					 	*
****************************************************/

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
	if (this != &other)
		AForm::operator=(other);
	return (*this);
}

/****************************************************
*					FUNCTIONS						*
****************************************************/

unsigned int	ShrubberyCreationForm::getMinSignGrade(void) const {
	return (_minSignGrade);
}

unsigned int	ShrubberyCreationForm::getMinExecGrade(void) const {
	return (_minExecGrade);
}

void	ShrubberyCreationForm::execute(const Bureaucrat& executor) const {
	try {
		if (!getIsSigned())
			throw FormNotSigned();
		if (executor.getGrade() > _minExecGrade)
			throw GradeTooHighException();
		std::cout << "ASCII trees!" << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << color("Error", RED) << "! " << e.what();
	}
}