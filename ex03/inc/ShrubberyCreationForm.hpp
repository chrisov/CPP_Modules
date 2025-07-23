#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include <fstream>
#include "AForm.hpp"

class Bureaucrat;

class ShrubberyCreationForm : public AForm {
	private:
		const std::string			_target;
		static const unsigned int	_minSignGrade = 145;
		static const unsigned int	_minExecGrade = 137;

	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm& other);
		~ShrubberyCreationForm();

		ShrubberyCreationForm&	operator=(const ShrubberyCreationForm& other);

		unsigned int	getMinSignGrade(void) const;
		unsigned int	getMinExecGrade(void) const;
		std::string		getTarget(void) const;
		void			execute(const Bureaucrat& executor) const override;
		static AForm*	newShrubbery(std::string target);
};

#endif