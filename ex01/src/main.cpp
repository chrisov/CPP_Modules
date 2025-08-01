#include "../inc/Span.hpp"

int main(void) {

		// Span	a;
		// try {
		// 	a.addNumber(6);
		// 	std::cout << a << std::endl;
		// 	a.addNumber(3);
		// 	std::cout << a << std::endl;
		// }
		// catch (const Span::ContainerAlreadyFullException& e) {
		// 	std::cerr << "Error! " << e.what() << std::endl;
		// }
		// Span sp = Span(100);
		// sp.randomFill();
		// std::cout << sp << std::endl;
		Span sp(6);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		sp.addNumber(18);
		std::cout << sp << std::endl;
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;

	return 0;
}