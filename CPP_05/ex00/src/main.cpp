#include "../inc/Bureaucrat.hpp"

int main(void) {
	
	Bureaucrat	*default_b = nullptr;
	Bureaucrat	*valid_b = nullptr;
	Bureaucrat	*invalid_b = nullptr;

	std::cout << "\nv============= INVALID PARAM CONSTRUCTOR ===========v" << std::endl;
	try {
		invalid_b = new Bureaucrat("Default", 151);
		invalid_b->incrementGrade();
		invalid_b->decrementGrade();
	}
	catch(const std::exception& e) {
		std::cerr << color("Error", RED) << "! " << e.what();
	}
	try {
		invalid_b = new Bureaucrat("Peter", 0);
		invalid_b->incrementGrade();
		invalid_b->decrementGrade();
	}
	catch(const std::exception& e) {
		std::cerr << color("Error", RED) << "! " << e.what();
	}
	std::cout << "^===================================================^\n" << std::endl;
	

	std::cout << "\nv=============== DEFAULT CONSTRUCTOR ==============v" << std::endl;
	try {
		default_b = new Bureaucrat();
		std::cout << *default_b << std::endl;
		default_b->incrementGrade();
		default_b->incrementGrade();
		default_b->decrementGrade();
		std::cout << *default_b << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << "Error creating the Bureaucrat! " << e.what() << std::endl;
	}
	std::cout << "^==================================================^\n" << std::endl;
	

	std::cout << "\nv================ PARAM CONSTRUCTOR ===============v" << std::endl;
	try {
		valid_b = new Bureaucrat("Peter", 4);
		std::cout << *valid_b << std::endl;
		valid_b->incrementGrade();
		valid_b->incrementGrade();
		valid_b->incrementGrade();
		valid_b->decrementGrade();
		std::cout << *valid_b << std::endl;
	}
	catch(const std::exception& e) {
		std::cerr << "Error creating parameterized Bureaucrat! " << e.what() << std::endl;
	}
	std::cout << "^==================================================^\n" << std::endl;


	std::cout << "\nv================ INVALID INCREMENT ================v" << std::endl;
	default_b->decrementGrade();
	std::cout << *default_b << std::endl;
	default_b->decrementGrade();
	std::cout << *default_b << std::endl;

	valid_b->incrementGrade();
	std::cout << *valid_b << std::endl;
	valid_b->incrementGrade();
	std::cout << *valid_b << std::endl;
	std::cout << "^===================================================^\n" << std::endl;



	delete default_b;
	delete valid_b;
}