#include "../inc/Fixed.hpp"

Fixed::Fixed() {
	std::cout << "Default constructor called" << std::endl;
	_result = 0;
}

Fixed::Fixed(const Fixed& other) {
	std::cout << "Copy constructor called" << std::endl;
	this->_result = other.getRawBits();
}

Fixed&	Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std:: endl;
	if (this != &other)
		this->_result = getRawBits();
	return (*this);
}

std::ostream&	operator<<(std::ostream& out, const Fixed& obj)
{
	out << obj.getRawBits();
	return (out);
}

Fixed::Fixed(const int num) {
	std::cout << "Int constructor called" << std::endl;
	_result = num / (1 << _fract);
}

Fixed::Fixed(const float num) {
	std::cout << "Float constructor called" << std::endl;
	_result = num / (1 << _fract);
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}
