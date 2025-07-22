#include "../inc/Bureaucrat.hpp"
#include "../inc/AForm.hpp"

/****************************************************
*				CONSTRUCTORS					 	*
****************************************************/

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150) {
	std::cout << "Bureaucrat '" << color(_name, YLW) << "' is " << color("created", GRN) << "!" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, unsigned int grade) : _name(name) {
	if (grade > 150)
		throw GradeTooLowException();
	else if (grade < 1)
		throw GradeTooHighException();
	_grade = grade;
	std::cout << "Bureaucrat '" << color(_name, YLW) << "' is " << color("created", GRN) << "!" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade) {
	std::cout << "Bureaucrat '" << color(_name, YLW) << "' is " << color("created", GRN) << "!" << std::endl;
}

Bureaucrat::~Bureaucrat() {
	std::cout << "'" << color(_name, YLW) << "' is " << color("destroyed", RED) << "!" << std::endl;
}

/****************************************************
*					OPERATORS					 	*
****************************************************/

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& other) {
	if (this != &other) {
		_grade = other._grade;
	}
	return (*this);
}

std::ostream&	operator<<(std::ostream& out, const Bureaucrat& obj) {
	out << "'" << color(obj.getName(), YLW) << "', bureaucrat grade: " << color(std::to_string(obj.getGrade()), YLW);
	return (out);
}

/****************************************************
*					FUNCTIONS					 	*
****************************************************/

const std::string	Bureaucrat::getName(void) const {
	return (_name);
}

unsigned int	Bureaucrat::getGrade(void) const {
	return (_grade);
}

void	Bureaucrat::incrementGrade(void) {
	try {
		if (_grade == 1) {
			std::cout << "Grade already " << color("max", GRN) << "!" << std::endl;
			throw std::exception();
		}
		std::cout << "Grade " << color("incremented", GRN) << "!" << std::endl;
		_grade--;
	}
	catch (const std::exception& e) {
		GradeTooLowException();
	}
}

void	Bureaucrat::decrementGrade(void) {
	try {
		if (_grade == 150) {
			std::cout << "Grade already " << color("min", RED) << "!" << std::endl;
			throw std::exception();
		}
		std::cout << "Grade " << color("decremented", RED) << "!" << std::endl;
		_grade++;
	}
	catch (const std::exception& e) {
		GradeTooHighException();
	}
}

void	Bureaucrat::signForm(AForm& form) {
	try {
		if (form.getIsSigned())
			throw AForm::FormAlreadySigned();
		std::cout << "'" << color(getName(), YLW) << "' " << color("signed", GRN) << " the '" << color(form.getName(), YLW) << "' form!" << std::endl;
		form.beSigned(*this);
	}
	catch (const std::exception& e) {
		std::cerr << color("Error", RED) << "! " << color(getName(), YLW) << " can't sign the '" << color(form.getName(), YLW) << "' form! " << e.what();
	}
}

void	Bureaucrat::executeForm(const AForm& form) const {
	form.execute(*this);
}

/****************************************************
*					EXCEPTIONS					 	*
****************************************************/


const char*	Bureaucrat::GradeTooHighException::what() const noexcept {
	return ("(Grade too \033[31mhigh\033[0m)");
}

const char*	Bureaucrat::GradeTooLowException::what() const noexcept {
	return ("(Grade too \033[31mlow\033[0m)");
}