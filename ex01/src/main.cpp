#include "../inc/Span.hpp"

int main(void) {

	std::cout << "\nv=========== DEFAULT CONSTRUCTOR ============v" << std::endl;
	{
		Span	cont;
		try {
			cont.addNumber(6);
			std::cout << color("\n\tCONTAINER\n", YLW) << cont << std::endl;
			cont.addNumber(3);
			std::cout << cont << std::endl;
		}
		catch (const Span::ContainerAlreadyFullException& e) {
			std::cerr << color("\nError", RED) << "! " << e.what() << std::endl;
		}
		try {
			std::cout << "Shortest span: " << color(std::to_string(cont.shortestSpan()), YLW) << std::endl;
		}
		catch (const Span::InvalidContainerSpanException& e) {
			std::cerr << color("Error", RED) << "! " << e.what() << std::endl;
		}
		try {
			std::cout << "Longest span: " << color(std::to_string(cont.longestSpan()), YLW) << std::endl;
		}
		catch (const Span::InvalidContainerSpanException& e) {
			std::cerr << color("Error", RED) << "! " << e.what() << std::endl;
		}
		std::cout << std::endl;
	}
	std::cout << "^============================================^\n" << std::endl;
	
	
	std::cout << "\nv============== MANUAL INSERT ===============v" << std::endl;
	{
		Span cont(6);
		cont.addNumber(6);
		cont.addNumber(3);
		cont.addNumber(17);
		cont.addNumber(9);
		cont.addNumber(11);
		int shortest = cont.shortestSpan();
		int longest = cont.longestSpan();
		std::cout << color("\n\tCONTAINER\n", YLW) << cont << std::endl;;
		std::cout << color("Shortest span", MGD) << ": " << color(std::to_string(shortest), YLW) << std::endl;
		std::cout << color("Longest span", CYA) << ": " << color(std::to_string(longest), YLW) << std::endl;
		std::cout << std::endl;
	}
	std::cout << "^============================================^\n" << std::endl;
	
	
	std::cout << "\nv=============== RANDOM FILL ================v" << std::endl;
	{
		Span cont = Span(100);
		cont.randomFill();
		int shortest = cont.shortestSpan();
		int longest = cont.longestSpan();
		std::cout << color("Shortest span", MGD) << ": " << shortest << std::endl;
		std::cout << color("Longest span", CYA) << ": " << longest << std::endl;
		std::cout << std::endl;
	}
	std::cout << "^============================================^\n" << std::endl;

	return 0;
}