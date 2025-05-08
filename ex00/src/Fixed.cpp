#include "../inc/Fixed.hpp"

Fixed::Fixed() {
	std::cout << "Default constructor called" << std::endl;
	Fixed::setRawBits(0);
}

Fixed::Fixed(const Fixed& other) {
	_result = other._result;
	std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	if (this != &other)
		this->_result = other._result;
	return (*this);
}

int	Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return (_result);
}

void	Fixed::setRawBits(int const raw) {
	_result = raw;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}