#include "../inc/ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

/****************************************************
*					CONSTRUCTORS					*
****************************************************/

ShrubberyCreationForm::ShrubberyCreationForm() : AForm::AForm("Default", _minSignGrade, _minExecGrade), _target("NULL") {
	std::cout << "Shrubbery '" << color(getName(), YLW) << "' is " << color("created", GRN) << "!" << std::endl;	
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string name, std::string target) : AForm::AForm(name, _minSignGrade, _minExecGrade), _target(target) {
	std::cout << "Shrubbery '" << color(getName(), YLW) << "' is " << color("created", GRN) << "!" << std::endl;	
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm::AForm(other), _target(other._target) {
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

std::string		ShrubberyCreationForm::getTarget(void) const {
	return (_target);
}

void	ShrubberyCreationForm::execute(const Bureaucrat& executor) const {
	try {
		if (!getIsSigned())
			throw FormNotSigned();
		if (executor.getGrade() > _minExecGrade)
			throw GradeTooHighException();
		std::string filename = _target + "_shrubbery";
		std::ofstream file(filename);
		if (file.is_open()) {
			file << R"(
				 *
			    /|\
			   /*|O\
			  /*/|\*\
			 /X/O|*\X\
			/X/*/X|O\*\
				|||
			)" << std::endl;
			file.close();
			std::cout << "'" << color(executor.getName(), YLW) << "': " << color(getName(), YLW) << "' " << color("executed", GRN) << "!" << std::endl;
		}
		else
			std::cerr << color("Failed", RED) << "to create '" << color(filename, YLW) << "'!" << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << "'" << color(executor.getName(), YLW) << "': " << "'" << color(getName(), YLW) << "' execution " << color("error", RED) << "! " << e.what();
	}
}