#include "../inc/Fixed.hpp"

//*************************************************
//					CONSTRUCTORS			  	  *
//*************************************************

Fixed::Fixed() {
	std::cout << "Default constructor called" << std::endl;
	Fixed::setRawBits(0);
}

Fixed::Fixed(const Fixed& other) {
	std::cout << "Copy constructor called" << std::endl;
	this->_result = other.getRawBits();
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

//*************************************************
//					OPERATORS				  	  *
//*************************************************

Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->_result = getRawBits();
	return (*this);
}

//*************************************************
//					FUNCTIONS				  	  *
//*************************************************

int	Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return (_result);
}

void	Fixed::setRawBits(int const raw) {
	_result = raw;
}
