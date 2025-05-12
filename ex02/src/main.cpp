#include "../inc/Fixed.hpp"

int main( void ) {
	Fixed a;
	Fixed const b = Fixed(5.05f);
	Fixed const c = Fixed(2);
	Fixed const d(Fixed(5.05f) + Fixed(2));

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	if (a > b)
		std::cout << "greater" << std::endl;
	else
		std::cout << "lesser" << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	// std::cout << b << std::endl;
	// std::cout << c << std::endl;
	std::cout << d << std::endl;
	std::cout << Fixed::max(a, b) << std::endl;
	return (0);
	}