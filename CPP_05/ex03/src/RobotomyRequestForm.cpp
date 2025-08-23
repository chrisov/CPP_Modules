#include "../inc/RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

/****************************************************
*					CONSTRUCTORS					*
****************************************************/

RobotomyRequestForm::RobotomyRequestForm() : AForm::AForm("RRF", _minSignGrade, _minExecGrade), _target("NULL") {
	std::cout << "Robotomy form '" << color(getName(), YLW) << "' is " << color("created", GRN) << "!" << std::endl;	
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm::AForm("RRF", _minSignGrade, _minExecGrade), _target(target) {
	std::cout << "Robotomy form '" << color(getName(), YLW) << "' is " << color("created", GRN) << "!" << std::endl;	
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm::AForm(other), _target(other._target) {
	std::cout << "Robotomy form '" << color(getName(), YLW) << "' is " << color("created", GRN) << "!" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << "Robotomy form '" << color(getName(), YLW) << "' is " << color("destroyed", RED) << "!" << std::endl;
}

/****************************************************
*					OPERATORS					 	*
****************************************************/

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
	if (this != &other)
		AForm::operator=(other);
	return (*this);
}

/****************************************************
*					FUNCTIONS						*
****************************************************/

unsigned int	RobotomyRequestForm::getMinSignGrade(void) const {
	return (_minSignGrade);
}

unsigned int	RobotomyRequestForm::getMinExecGrade(void) const {
	return (_minExecGrade);
}

std::string		RobotomyRequestForm::getTarget(void) const {
	return (_target);
}

void	RobotomyRequestForm::execute(const Bureaucrat& executor) const {
	try {
		std::srand(static_cast<unsigned int>(std::time(nullptr)));
		if (!getIsSigned())
			throw FormNotSigned();
		if (executor.getGrade() > _minExecGrade)
			throw GradeTooHighException();
		std::cout << " * Make drilling noises *" << std::endl;
		if (std::rand() % 2 == 0)
			std::cout << "'" << color(_target, YLW) << "': " << color("Successfully", GRN) << " robotomized!" << std::endl;
		else
			std::cout << "Robotomy " << color("failed", RED) << "!" << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << "'" << color(executor.getName(), YLW) << "': " << "'" << color(getName(), YLW) << "' execution " << color("error", RED) << "! " << e.what();
	}
}

AForm*	RobotomyRequestForm::newRobotomy(std::string target) {
	return (new RobotomyRequestForm(target));
}