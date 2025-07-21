#include "../inc/Bureaucrat.hpp"

/****************************************************
*				CONSTRUCTORS					 	*
****************************************************/

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150) {
	std::cout << "Default " << color("Bureaucrat", YLW) << color(" constructor", GRN) << " called!" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, unsigned int grade) : _name(name) {
	if (grade > 150)
		throw GradeTooHighException();
	else if (grade < 1)
		throw GradeTooLowException();
	_grade = grade;
	std::cout << "Parameterized " << color("Bureaucrat", YLW) << color(" constructor", GRN) << " called!" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade) {
	std::cout << color("Bureaucrat", YLW) << " copy " << color("constructor", GRN) << " called!" << std::endl;
}

Bureaucrat::~Bureaucrat() {
	std::cout << color("Bureaucrat", YLW) << color(" destructor", RED) << " called!" << std::endl;
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

const char*	Bureaucrat::GradeTooHighException::what() const noexcept {
	return ("Grade too high!\n");
}

const char*	Bureaucrat::GradeTooLowException::what() const noexcept {
	return ("Grade too low!\n");
}