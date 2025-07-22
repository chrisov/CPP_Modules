#include "../inc/Bureaucrat.hpp"
#include "../inc/AForm.hpp"
#include "../inc/ShrubberyCreationForm.hpp"

int main(void) {
	{
		Bureaucrat	*supervisor = nullptr;
		Bureaucrat	*intern = nullptr;
		AForm		*form = nullptr;
	
		std::cout << "\nv=============== VALID CONSTRUCTORS ==============v" << std::endl;
		try {
			supervisor = new Bureaucrat("VP_Manolis", 10);
		}
		catch (const std::exception& e) {
			std::cerr << color("Error", RED) << " creating the " << color("Bureaucrat", YLW) << "! " << e.what();
		}
		try {
			form = new ShrubberyCreationForm("SCF");
		}
		catch (const std::exception& e) {
			std::cerr << color("Error", RED) << " creating the " << color("Form", YLW) << "! " << e.what();
		}
		std::cout << "\n" << *form;
		std::cout << "^=================================================^\n" << std::endl;
		
		std::cout << "\nv================== SIGNING =================v" << std::endl;
		intern = new Bureaucrat("INT_Thanasis", 149);
		intern->signForm(*form);
		intern->executeForm(*form);
		supervisor->signForm(*form);
		supervisor->signForm(*form);
		supervisor->signForm(*form);
		std::cout << "^============================================^\n" << std::endl;
		
		delete form;
		delete supervisor;
		delete intern;
	}

}