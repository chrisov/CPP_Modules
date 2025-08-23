#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <exception>

#include "Colors.hpp"

class Bureaucrat;

class Form {

	private:
		const std::string	_name;
		const unsigned int	_gradeToSign;
		const unsigned int	_gradeToExecute;
		bool				_isSigned;

	public:
		Form();
		Form(std::string name, unsigned int sign_grade);
		Form(const Form& other);
		~Form();

		Form&	operator=(const Form& other);

		std::string		getName(void) const;
		unsigned int	getGradeToSign(void) const;
		unsigned int	getGradeToExecute(void) const;
		bool			getIsSigned(void) const;
		void			beSigned(const Bureaucrat& bur);

		class GradeTooHighException : public std::exception {
			public:
				const char* what(void) const noexcept override;		
		};
		class GradeTooLowException : public std::exception {
			public:
				const char* what(void) const noexcept override;		
		};
};

std::ostream& operator<<(std::ostream& out, const Form& obj);

#endif