#include "../inc/Fixed.hpp"

//*************************************************
//					CONSTRUCTORS			  	  *
//*************************************************

Fixed::Fixed() {
	setRawBits(roundf(0 * (1 << _fract)));
}

Fixed::Fixed(const Fixed& other) {
	*this = other;
}

Fixed::Fixed(const int num) {
	setRawBits(roundf(num * (1 << _fract)));
}

Fixed::Fixed(const float num) {
	setRawBits(roundf(num * (1 << _fract)));
}

Fixed::~Fixed() {}


//*************************************************
//					INCREMENTATION				  *
//*************************************************

Fixed	Fixed::operator++(void) {
	this->_result++;
	return (*this);
}

Fixed	Fixed::operator++(int) {
	Fixed temp = *this;
	++(*this)._result;
	return (temp);
}

Fixed	Fixed::operator--(void) {
	this->_result--;
	return (*this);
}

Fixed	Fixed::operator--(int) {
	Fixed temp = *this;
	--(*this)._result;
	return (temp);
}

//*************************************************
//					OPERATORS					  *
//*************************************************

Fixed	Fixed::operator+(const Fixed& other) {
	Fixed	res;

	long long add = static_cast<long long>(_result) * other._result;
	res._result = static_cast<int>(add >> _fract);
	return (res);
}

Fixed	Fixed::operator-(const Fixed& other) {
	Fixed	res;

	long long subtr = static_cast<long long>(_result) * other._result;
	res._result = static_cast<int>(subtr >> _fract);
	return (res);
}

Fixed	Fixed::operator*(const Fixed& other) const {
	Fixed	res;

	long long mult = static_cast<long long>(_result) * other._result;
	res._result = static_cast<int>(mult >> _fract);
	return (res);
}

Fixed	Fixed::operator/(const Fixed& other) {
	Fixed res;
	
	long long div = static_cast<long long>(_result) / other._result;
	res._result = static_cast<int>(div >> _fract);
	return (res);
}

Fixed&	Fixed::operator=(const Fixed& other)
{
	if (this != &other)
		this->_result = other._result;
	return (*this);
}

std::ostream&	operator<<(std::ostream& out, const Fixed& obj)
{
	out << obj.toFloat();
	return (out);
}

//*************************************************
//					COMPARISON					  *
//*************************************************

bool	Fixed::operator>(const Fixed& other) const {
	if (this->getRawBits() > other.getRawBits())
		return(true);
	return (false);
}

bool	Fixed::operator>=(const Fixed& other) const {
	if (this->getRawBits() >= other.getRawBits())
		return(true);
	return (false);
}

bool	Fixed::operator<(const Fixed& other) const {
	if (this->getRawBits() < other.getRawBits())
		return(true);
	return (false);
}

bool	Fixed::operator<=(const Fixed& other) const {
	if (this->getRawBits() <= other.getRawBits())
		return(true);
	return (false);
}

bool	Fixed::operator==(const Fixed& other) const {
	if (this->getRawBits() == other.getRawBits())
		return(true);
	return (false);
}

bool	Fixed::operator!=(const Fixed& other) const {
	if (this->getRawBits() != other.getRawBits())
		return(true);
	return (false);
}

//*************************************************
//					FUNCTIONS				  	  *
//*************************************************

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

const Fixed&	Fixed::min(const Fixed& a, const Fixed& b) {
	return ((a < b) ? a : b);
}

Fixed&	Fixed::min(Fixed& a, Fixed& b) {
	return ((a < b) ? a : b);
}

const Fixed&	Fixed::max(const Fixed& a, const Fixed& b) {
	return ((a > b) ? a : b);
}

Fixed&	Fixed::max(Fixed& a, Fixed& b) {
	return ((a > b) ? a : b);
}