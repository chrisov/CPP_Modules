#include "Point.hpp"

//*************************************************
//					CONSTRUCTORS			  	  *
//*************************************************

Point::Point() : _x(Fixed(0)), _y(Fixed(0)) {}

Point::Point(const Point& other) : _x(other._x), _y(other._y) {}

Point::Point(Fixed const &x, Fixed const &y) : _x(x), _y(y) {}

Point::~Point() {}

//*************************************************
//					OPERATORS				  	  *
//*************************************************

Point	Point::operator-(const Point& other) const {
	Point	res = Point(_x - other._x, _y - other._y);
	return (res);
}

std::ostream&	operator<<(std::ostream& out, const Point& other) {
	out << "(" << other._x << "," << other._y << ")";
	return (out);
}

//*************************************************
//					FUNCTIONS				  	  *
//*************************************************

Fixed	Point::getX(void) const {
	return (_x);
}

Fixed	Point::getY(void) const {
	return (_y);
}