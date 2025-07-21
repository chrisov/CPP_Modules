#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>
#include "Colors.hpp"

class Bureaucrat {

	private:
		const std::string	_name;
		unsigned int		_grade;

	public:
		Bureaucrat();
		Bureaucrat(const std::string name, unsigned int grade);
		Bureaucrat(const Bureaucrat& other);
		~Bureaucrat();

		Bureaucrat& operator=(const Bureaucrat& other);

		const std::string	getName(void) const;
		unsigned int		getGrade(void) const;
		void				incrementGrade(void);
		void				decrementGrade(void);

		class GradeTooHighException : public std::exception {
			public :
				const char*	what() const noexcept override;
		};
		class GradeTooLowException : public std::exception {
			public :
				const char*	what() const noexcept override;
		};
};

std::ostream&	operator<<(std::ostream& out, const Bureaucrat& obj);

#endif