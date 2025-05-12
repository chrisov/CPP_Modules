#ifndef POINT_HPP
# define POINT_HPP

#include <iostream>
#include "../../ex02/inc/Fixed.hpp"

class Point {

	private:
		Fixed const	_x;
		Fixed const	_y;

	public:
		Point();
		Point(const Point& other);
		Point(const float &x, const float &y);
		~Point();

		friend std::ostream&	operator<<(std::ostream& out, const Point& other);
		Point	operator-(const Point& other) const;

		Fixed	getX(void) const;
		Fixed	getY(void) const;
};
	
bool bsp(Point const a, Point const b, Point const c, Point const p);

#endif