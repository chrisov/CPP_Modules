#include "../inc/Bureaucrat.hpp"
#include "../inc/Form.hpp"

int main(void) {
	Bureaucrat	*supervisor = nullptr;
	Bureaucrat	*junior = nullptr;
	Form		*form = nullptr;
	
	std::cout << "\nv============== INVALID CONSTRUCTORS =============v" << std::endl;
	try {
		supervisor = new Bureaucrat("CEO", 0);
	}
	catch (const std::exception& e) {
		std::cerr << color("Error", RED) << "! " << color("Bureaucrat", YLW) << " is not created! " << e.what() << std::endl;
	}
	try {
		junior = new Bureaucrat("J_Paschalis", 151);
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
	std::cout << "^=================================================^\n" << std::endl;


	std::cout << "\nv=============== VALID CONSTRUCTORS ==============v" << std::endl;
	try {
		supervisor = new Bureaucrat("VP_Manolis", 10);
	}
	catch (const std::exception& e) {
		std::cerr << color("Error", RED) << " creating the " << color("Bureaucrat", YLW) << "! " << e.what();
	}
	try {
		junior = new Bureaucrat("J_Thanasis", 100);
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
	
	
	std::cout << "\nv===================== SIGNING ===================v" << std::endl;
	junior->signForm(*form);
	supervisor->signForm(*form);
	supervisor->signForm(*form);
	std::cout << "^=================================================^\n" << std::endl;	

	delete form;
	delete supervisor;
	delete junior;
}