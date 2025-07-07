#ifndef POINT_HPP
# define POINT_HPP

#include <iostream>
#include "Fixed.hpp"

class Point {

	private:
		Fixed const	_x;
		Fixed const	_y;

	public:
		Point();
		Point(const Point& other);
		Point(Fixed const &x, Fixed const &y);
		~Point();

		friend std::ostream&	operator<<(std::ostream& out, const Point& other);
		
		Point	operator-(const Point& other) const;
		Point&	operator=(const Point& other) = delete;

		Fixed	getX(void) const;
		Fixed	getY(void) const;
};
	
bool bsp(Point const a, Point const b, Point const c, Point const p);

#endif