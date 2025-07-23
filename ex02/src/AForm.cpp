#include "../inc/AForm.hpp"
#include "../inc/Bureaucrat.hpp"

/****************************************************
*					CONSTRUCTORS				 	*
****************************************************/

AForm::AForm() : _name("Default"), _gradeToSign(1), _gradeToExecute(1), _isSigned(false) {
	std::cout << "AForm '" << color(_name, YLW) << "' is " << color("created", GRN) << "!" << std::endl;
}

AForm::AForm(std::string name, unsigned int sign_grade, unsigned int exec_grade) : _name(name), _gradeToSign(sign_grade), _gradeToExecute(exec_grade), _isSigned(false) {
	if (_gradeToSign > 150)
		throw GradeTooLowException();
	else if (_gradeToSign < 1)
		throw GradeTooHighException();
	std::cout << "AForm '" << color(_name, YLW) << "' is " << color("created", GRN) << "!" << std::endl;
}


AForm::AForm(const AForm& other) : _name(other._name), _gradeToSign(1), _gradeToExecute(1), _isSigned(other._isSigned) {
	std::cout << "AForm '" << color(_name, YLW) << "' is " << color("created", GRN) << "!" << std::endl;
}

AForm::~AForm() {
	std::cout << "AForm '" << color(_name, YLW) << "' is " << color("destroyed", RED) << "!" << std::endl;
}

/****************************************************
*					OPERATORS					 	*
****************************************************/

AForm&	AForm::operator=(const AForm& other) {
	if (this != &other) {
		_isSigned = other._isSigned;
	}
	return (*this);
}

std::ostream&	operator<<(std::ostream& out, const AForm& obj) {
	out << "AForm name:'" << color(obj.getName(), YLW);
	out << "'\nGrade to sign: " << color(std::to_string(obj.getGradeToSign()), YLW);
	out << "\nGrade to exec: " << color(std::to_string(obj.getGradeToExecute()), YLW);
	out << "\nSigned: " << (obj.getIsSigned() ? color("YES", GRN) : color("NO", RED)) << std::endl;
	return (out);
}

/****************************************************
*					FUNCTIONS						*
****************************************************/

std::string	AForm::getName(void) const {
	return (_name);
}

unsigned int	AForm::getGradeToSign(void) const {
	return (_gradeToSign);
}

unsigned int	AForm::getGradeToExecute(void) const {
	return (_gradeToExecute);
}

bool	AForm::getIsSigned(void) const {
	return (_isSigned);
}

void	AForm::beSigned(const Bureaucrat& bur) {
	if (bur.getGrade() >= _gradeToSign)
		throw GradeTooHighException();
	_isSigned = true;
}

/****************************************************
*					FUNCTIONS						*
****************************************************/

const char*	AForm::GradeTooHighException::what(void) const noexcept {
	return ("(Grade too \033[31mhigh\033[0m)\n");
}

const char*	AForm::GradeTooLowException::what(void) const noexcept {
	return ("(Grade too \033[31mlow\033[0m)\n");
}

const char*	AForm::FormNotSigned::what(void) const noexcept {
	return ("(Form \033[31mnot\033[0m signed)\n");
}

const char*	AForm::FormAlreadySigned::what(void) const noexcept {
	return ("(Form already \033[32malready\033[0m signed)\n");
}
