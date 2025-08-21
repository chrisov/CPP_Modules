#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include "AForm.hpp"

class Bureaucrat;

class PresidentialPardonForm : public AForm {
	private:
		const std::string			_target;
		static const unsigned int	_minSignGrade = 25;
		static const unsigned int	_minExecGrade = 5;

	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm& other);
		~PresidentialPardonForm();

		PresidentialPardonForm&	operator=(const PresidentialPardonForm& other);

		unsigned int	getMinSignGrade(void) const;
		unsigned int	getMinExecGrade(void) const;
		std::string		getTarget(void) const;
		void			execute(const Bureaucrat& executor) const override;
};

#endif