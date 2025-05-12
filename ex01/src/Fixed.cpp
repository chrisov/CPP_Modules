#include "../inc/Fixed.hpp"

Fixed&	Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std:: endl;
	if (this != &other)
		this->_result = other._result;
	return (*this);
}

std::ostream&	operator<<(std::ostream& out, const Fixed& obj)
{
	out << obj.getRawBits() / static_cast<float>(1 << obj._fract);
	return (out);
}

Fixed::Fixed() {
	std::cout << "Default constructor called" << std::endl;
	setRawBits(0);
}

Fixed::Fixed(const Fixed& other) {
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed::Fixed(const int num) {
	std::cout << "Int constructor called" << std::endl;
	setRawBits(roundf(num * (1 << _fract)));
}

Fixed::Fixed(const float num) {
	std::cout << "Float constructor called" << std::endl;
	setRawBits(roundf(num * (1 << _fract)));
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits(void) const {
	return (this->_result);
}

void	Fixed::setRawBits(int const raw) {
	this->_result = raw;
}

int	Fixed::toInt(void) const {
	return(this->_result / static_cast<int>(1 << this->_fract));
}

float	Fixed::toFloat(void) const {
	return(this->_result / static_cast<float>(1 << this->_fract));
}
