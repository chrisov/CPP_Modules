#include "../inc/Bureaucrat.hpp"
#include "../inc/Form.hpp"

int main(void) {
	{
		std::cout << "\nv============== INVALID CONSTRUCTORS =============v" << std::endl;
		Bureaucrat	*supervisor = nullptr;
		Bureaucrat	*intern = nullptr;
		Form		*form = nullptr;
	
		try {
			supervisor = new Bureaucrat("CEO", 0);
		}
		catch (const std::exception& e) {
			std::cerr << color("Error", RED) << "! " << color("Bureaucrat", YLW) << " is not created! " << e.what() << std::endl;
		}
		try {
			intern = new Bureaucrat("Intern", 151);
		}
		catch (const std::exception& e) {
			std::cerr << color("Error", RED) << "! " << color("Bureaucrat", YLW) << " is not created! " << e.what() << std::endl;
		}
		try {
			form = new Form("Inv_form", 0);
		}
		catch (const std::exception& e) {
			std::cerr << color("Error", RED) << "! " << color("Form", YLW) << " is not created! " << e.what();
		}
		try {
			form = new Form("Inv_form", 200);
		}
		catch (const std::exception& e) {
			std::cerr << color("Error", RED) << "! " << color("Form", YLW) << " is not created! " << e.what();
		}
		delete supervisor;
		delete intern;
		delete form;
		std::cout << "^=================================================^\n" << std::endl;
	}
	{
		Bureaucrat	*supervisor = nullptr;
		Bureaucrat	*intern = nullptr;
		Form		*form = nullptr;
	
		std::cout << "\nv=============== VALID CONSTRUCTORS ==============v" << std::endl;
		try {
			supervisor = new Bureaucrat("VP_Manolis", 10);
		}
		catch (const std::exception& e) {
			std::cerr << color("Error", RED) << " creating the " << color("Bureaucrat", YLW) << "! " << e.what();
		}
		try {
			form = new Form("Visa", 30);
		}
		catch (const std::exception& e) {
			std::cerr << color("Error", RED) << " creating the " << color("Form", YLW) << "! " << e.what();
		}
		std::cout << "^=================================================^\n" << std::endl;
		
		
		std::cout << "\nv================== SIGNING =================v" << std::endl;
		intern = new Bureaucrat("INT_Thanasis", 100);
		intern->signForm(*form);
		supervisor->signForm(*form);
		supervisor->signForm(*form);
		supervisor->signForm(*form);
		std::cout << "^============================================^\n" << std::endl;
		
		delete form;
		delete supervisor;
		delete intern;
	}

}