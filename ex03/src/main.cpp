#include "../inc/Point.hpp"
#include "../../ex02/inc/Fixed.hpp"

int main(void) {
	Point t1(0,0);
	Point t2(1,0);
	Point t3(0,1);
	Point c(-0.5, 0);

	if (bsp(t1, t2, t3, c))
		std::cout << "Point " << c << "belongs to the triangle" << std::endl;
	else
		std::cout << "Point " << c << "doesn't belong to the triangle" << std::endl;
	return (0);
	}