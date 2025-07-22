#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <exception>

#include "Colors.hpp"

class Bureaucrat;

class AForm {

	private:
		const std::string	_name;
		const unsigned int	_gradeToSign;
		const unsigned int	_gradeToExecute;
		bool				_isSigned;

	public:
		AForm();
		AForm(std::string name, unsigned int sign_grade, unsigned int exec_grade);
		AForm(const AForm& other);
		virtual ~AForm();

		AForm&	operator=(const AForm& other);

		std::string		getName(void) const;
		unsigned int	getGradeToSign(void) const;
		unsigned int	getGradeToExecute(void) const;
		bool			getIsSigned(void) const;
		void			beSigned(const Bureaucrat& bur);
		// void			prepareExecute(const Bureaucrat& executor);
		virtual void	execute(const Bureaucrat& executor) const = 0;

		class GradeTooHighException : public std::exception {
			public:
				const char* what(void) const noexcept override;		
		};
		class GradeTooLowException : public std::exception {
			public:
				const char* what(void) const noexcept override;		
		};
		class FormNotSigned : public std::exception {
			public:
				const char*	what(void) const noexcept override;
		};
		class FormAlreadySigned : public std::exception {
			public:
				const char*	what(void) const noexcept override;
		};
};

std::ostream& operator<<(std::ostream& out, const AForm& obj);

#endif