#include "../inc/PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

/****************************************************
*					CONSTRUCTORS					*
****************************************************/

PresidentialPardonForm::PresidentialPardonForm() : AForm::AForm("PPF", _minSignGrade, _minExecGrade), _target("NULL") {
	std::cout << "Presidential form'" << color(getName(), YLW) << "' is " << color("created", GRN) << "!" << std::endl;	
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm::AForm("PPF", _minSignGrade, _minExecGrade), _target(target) {
	std::cout << "Presidential form'" << color(getName(), YLW) << "' is " << color("created", GRN) << "!" << std::endl;	
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm::AForm(other), _target(other._target) {
	std::cout << "Presidential form'" << color(getName(), YLW) << "' is " << color("created", GRN) << "!" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << "Presidential form '" << color(getName(), YLW) << "' is " << color("destroyed", RED) << "!" << std::endl;
}

/****************************************************
*					OPERATORS					 	*
****************************************************/

PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
	if (this != &other)
		AForm::operator=(other);
	return (*this);
}

/****************************************************
*					FUNCTIONS						*
****************************************************/

unsigned int	PresidentialPardonForm::getMinSignGrade(void) const {
	return (_minSignGrade);
}

unsigned int	PresidentialPardonForm::getMinExecGrade(void) const {
	return (_minExecGrade);
}

std::string		PresidentialPardonForm::getTarget(void) const {
	return (_target);
}

void	PresidentialPardonForm::execute(const Bureaucrat& executor) const {
	try {
		if (!getIsSigned())
			throw FormNotSigned();
		if (executor.getGrade() > _minExecGrade)
			throw GradeTooHighException();
		std::cout << "'" << color(_target, YLW) << "' has been " << color("pardoned", GRN) << " by Zaphod Beeblebrox!" << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << "'" << color(executor.getName(), YLW) << "': " << "'" << color(getName(), YLW) << "' execution " << color("error", RED) << "! " << e.what();
	}
}

AForm*	PresidentialPardonForm::newPresidential(std::string target) {
	return (new PresidentialPardonForm(target));
}