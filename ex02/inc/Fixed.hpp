#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {

private:
	int						_result;
	static const int		_fract = 8;

public:
	Fixed();
	Fixed(const int num);
	Fixed(const float num);
	Fixed(const Fixed& other);
	~Fixed();
	
	Fixed&					operator=(const Fixed& other);
	Fixed					operator+(const Fixed	& other);
	Fixed					operator-(const Fixed& other);
	Fixed					operator*(const Fixed& other) const;	
	Fixed					operator/(const Fixed& other);	

	Fixed					operator++(void);
	Fixed					operator++(int);
	Fixed					operator--(void);
	Fixed					operator--(int);

	bool					operator>(const Fixed& other) const;
	bool					operator>=(const Fixed& other) const;
	bool					operator<(const Fixed& other) const;
	bool					operator<=(const Fixed& other) const;
	bool					operator==(const Fixed& other) const;
	bool					operator!=(const Fixed& other) const;
	
	int						getRawBits(void) const;
	void					setRawBits(int const raw);
	float					toFloat(void) const;
	int						toInt(void) const;	
	static const Fixed&		min(const Fixed& a, const Fixed& b);
	static const Fixed&		max(const Fixed& a, const Fixed& b);
	static Fixed&			min(Fixed& a, Fixed& b);
	static Fixed&			max(Fixed& a, Fixed& b);
};

std::ostream&	operator<<(std::ostream& out, const Fixed& other);

#endif