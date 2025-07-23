#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "AForm.hpp"

class Bureaucrat;

class RobotomyRequestForm : public AForm {
	private:
		const std::string			_target;
		static const unsigned int	_minSignGrade = 72;
		static const unsigned int	_minExecGrade = 45;

	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string name, std::string target);
		RobotomyRequestForm(const RobotomyRequestForm& other);
		~RobotomyRequestForm();

		RobotomyRequestForm&	operator=(const RobotomyRequestForm& other);

		unsigned int	getMinSignGrade(void) const;
		unsigned int	getMinExecGrade(void) const;
		std::string		getTarget(void) const;
		void			execute(const Bureaucrat& executor) const override;
};

#endif