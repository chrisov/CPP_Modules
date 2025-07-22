#include "../inc/Form.hpp"
#include "../inc/Bureaucrat.hpp"

/****************************************************
*					CONSTRUCTORS				 	*
****************************************************/

Form::Form() : _name("Default"), _gradeToSign(1), _gradeToExecute(1), _isSigned(false) {
	std::cout << "Form '" << color(_name, YLW) << "' is " << color("created", GRN) << "!" << std::endl;
}

Form::Form(std::string name, unsigned int sign_grade) : _name(name), _gradeToSign(sign_grade), _gradeToExecute(1), _isSigned(false) {
	if (_gradeToSign > 150)
		throw GradeTooLowException();
	else if (_gradeToSign < 1)
		throw GradeTooHighException();
	std::cout << "Form '" << color(_name, YLW) << "' is " << color("created", GRN) << "!" << std::endl;
}


Form::Form(const Form& other) : _name(other._name), _gradeToSign(1), _gradeToExecute(1), _isSigned(other._isSigned) {
	std::cout << "Form '" << color(_name, YLW) << "' is " << color("created", GRN) << "!" << std::endl;
}

Form::~Form() {
	std::cout << "'" << color(_name, YLW) << "' is " << color("destroyed", RED) << "!" << std::endl;
}

/****************************************************
*					OPERATORS					 	*
****************************************************/

Form&	Form::operator=(const Form& other) {
	if (this != &other) {
		_isSigned = other._isSigned;
	}
	return (*this);
}

std::ostream&	operator<<(std::ostream& out, const Form& obj) {
	out << "Form '" << obj.getName() << "', grade to sign: " << obj.getGradeToSign() << "!" << std::endl;
	return (out);
}

/****************************************************
*					FUNCTIONS						*
****************************************************/

std::string	Form::getName(void) const {
	return (_name);
}

unsigned int	Form::getGradeToSign(void) const {
	return (_gradeToSign);
}

unsigned int	Form::getGradeToExecute(void) const {
	return (_gradeToExecute);
}

bool	Form::getIsSigned(void) const {
	return (_isSigned);
}

void	Form::beSigned(const Bureaucrat& bur) {
	if (bur.getGrade() >= _gradeToSign)
		throw GradeTooHighException();
	_isSigned = true;
}

const char*	Form::GradeTooHighException::what(void) const noexcept {
	return ("(Grade too \033[31mhigh\033[0m)\n");
}

const char*	Form::GradeTooLowException::what(void) const noexcept {
	return ("(Grade too \033[31mlow\033[0m)\n");
}