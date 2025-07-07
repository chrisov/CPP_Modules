#include "../inc/Fixed.hpp"

int main( void ) {
	Fixed a;
	Fixed const b(Fixed(5.05f) * Fixed(2.f));

	std::cout << "a= " << a << std::endl;
	std::cout << "++a= " << ++a << std::endl;
	std::cout << "a= " << a << std::endl;
	std::cout << "a++= " << a++ << std::endl;
	std::cout << std::endl;
	
	std::cout << "a= " << a << std::endl;
	std::cout << "b= " << b << std::endl;
	std::cout << "max(a,b)= " << Fixed::max(a, b) << std::endl;
	std::cout << std::endl;

	if (a > b)
		std::cout << "a greater than b" << std::endl;
	else
		std::cout << "b greater than a" << std::endl;
	std::cout << std::endl;

	std::cout << "a + b: " << (a + b) << std::endl;
	std::cout << "a - b: " << (a - b) << std::endl;
	std::cout << "a * b: " << (a * b) << std::endl;
	std::cout << "b / 2: " << Fixed(Fixed(b) / Fixed(2.f)) << std::endl;
	return (0);
}