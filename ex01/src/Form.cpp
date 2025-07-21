#include "../inc/Form.hpp"

/****************************************************
*					CONSTRUCTORS				 	*
****************************************************/

Form::Form() : _name("Default"), _gradeToSign(1), _gradeToExecute(1), _isSigned(false) {
	std::cout << "Default Form constructor called!" << std::endl;
}

Form::Form(std::string name, unsigned int sign_grade) : _name(name), _gradeToSign(sign_grade) {
	std::cout << "Parameterized Form constructor called!" << std::endl;
}


Form::Form(const Form& other) : _name(other._name), _gradeToSign(1), _gradeToExecute(1), _isSigned(other._isSigned) {
	std::cout << "Copy Form constructor called!" << std::endl;
}

Form::~Form() {
	std::cout << "Form destructor called!" << std::endl;
}

/****************************************************
*					OPERATORS					 	*
****************************************************/

Form&	Form::operator=(const Form& other) {
	if (this != &other) {
		_isSigned = other._isSigned;
	}
}

std::ostream&	operator<<(std::ostream& out, const Form& obj) {
	out << "Form '" << obj.getName() << "', grade to sign: " << obj.getGradeToSign() << "!" << std::endl;
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
	try {
		if (bur.getGrade() >= _gradeToSign)
			throw std::exception();
		_isSigned = !_isSigned;
	}
	catch (const std::exception& e) {
		GradeTooHighException();
	}
}

const char*	Form::GradeTooHighException::what(void) const noexcept {
	return ("Grade too high!");
}

const char*	Form::GradeTooLowException::what(void) const noexcept {
	return ("Grade too low!");
}