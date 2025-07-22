#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include "AForm.hpp"

class Bureaucrat;

class ShrubberyCreationForm : public AForm {
	private:
		static const unsigned int	_minSignGrade = 145;
		static const unsigned int	_minExecGrade = 137;

	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string name);
		ShrubberyCreationForm(const ShrubberyCreationForm& other);
		~ShrubberyCreationForm();

		ShrubberyCreationForm&	operator=(const ShrubberyCreationForm& other);

		unsigned int	getMinSignGrade(void) const;
		unsigned int	getMinExecGrade(void) const;
		void			execute(const Bureaucrat& executor) const override;
};

#endif