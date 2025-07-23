#include "../inc/Bureaucrat.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"

int main(void) {
	Bureaucrat	*supervisor = nullptr;
	Bureaucrat	*junior = nullptr;
	
	std::cout << "\nv=============== VALID CONSTRUCTORS ==============v" << std::endl;
	try {
		supervisor = new Bureaucrat("VP_Manolis", 5);
	}
	catch (const std::exception& e) {
		std::cerr << color("Error", RED) << " creating the " << color("Bureaucrat", YLW) << "! " << e.what();
	}
	try {
		junior = new Bureaucrat("INT_Thanasis", 149);
	}
	catch (const std::exception& e) {
		std::cerr << color("Error", RED) << " creating the " << color("Bureaucrat", YLW) << "! " << e.what();
	}
	std::cout << "\n" << *supervisor << "\n" << *junior << std::endl;
	std::cout << "^=================================================^\n" << std::endl;

	{
		std::cout << "\nv=================== SHRUBBERY ===================v" << std::endl;
		AForm	*form = nullptr;
		try {
			form = new ShrubberyCreationForm("home");
		}
		catch (const std::exception& e) {
			std::cerr << color("Error", RED) << " creating the " << color("Form", YLW) << "! " << e.what();
		}
		
		std::cout << "\n" << *form << std::endl;
		junior->signForm(*form);
		supervisor->signForm(*form);
		junior->executeForm(*form);
		supervisor->executeForm(*form);
		
		std::cout << std::endl;
		delete form;
		std::cout << "^=================================================^\n" << std::endl;
	}
	{
		std::cout << "\nv=================== ROBOTOMY ====================v" << std::endl;
		AForm	*form = nullptr;

		try {
			form = new RobotomyRequestForm("Koulis");
		}
		catch (const std::exception& e) {
			std::cerr << color("Error", RED) << " creating the " << color("Form", YLW) << "! " << e.what();
		}
		
		std::cout << "\n" << *form << std::endl;
		junior->signForm(*form);
		supervisor->signForm(*form);
		junior->executeForm(*form);
		supervisor->executeForm(*form);
		
		std::cout << std::endl;
		delete form;
		std::cout << "^=================================================^\n" << std::endl;
	}
	{
		std::cout << "\nv================= PRESIDENTIAL ==================v" << std::endl;
		AForm	*form = nullptr;

		try {
			form = new PresidentialPardonForm("Elon Musk");
		}
		catch (const std::exception& e) {
			std::cerr << color("Error", RED) << " creating the " << color("Form", YLW) << "! " << e.what();
		}
		
		std::cout << "\n" << *form << std::endl;
		junior->signForm(*form);
		supervisor->signForm(*form);
		junior->executeForm(*form);
		supervisor->executeForm(*form);
		
		std::cout << std::endl;
		delete form;
		std::cout << "^=================================================^\n" << std::endl;
	}

	delete supervisor;
	delete junior;
}