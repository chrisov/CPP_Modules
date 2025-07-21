#include "../inc/Bureaucrat.hpp"
#include "../inc/Form.hpp"

int main(void) {
	Bureaucrat	*valid_b = nullptr;
	Form		valid_form("Visa", 50);

	std::cout << "\nv================ VALID CONSTRUCTOR ===============v" << std::endl;
	try {
		valid_b = new Bureaucrat("Valid_Peter", 30);

	}
	catch (const std::exception& e) {
		std::cerr << "Error creating the Bureaucrat! " << e.what() << std::endl;
	}
	std::cout << "^==================================================^\n" << std::endl;
	

	std::cout << "\nv================ VALID CONSTRUCTOR ===============v" << std::endl;
	try {
		valid_b = new Bureaucrat("Peter", 30);
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


	delete default_b;
	delete valid_b;
}