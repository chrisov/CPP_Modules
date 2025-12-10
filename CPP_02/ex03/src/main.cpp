#include "../inc/Point.hpp"
#include "../inc/Fixed.hpp"

int main(void) {
	Point t1(0,0);
	Point t2(4,0);
	Point t3(0,4);
	Point c(0.1f, 3.9f);

	if (bsp(t1, t2, t3, c))
		std::cout << "Point " << c << " belongs to the triangle: [" << t1 << "," << t2 << "," << t3 << "]" << std::endl;
	else
		std::cout << "Point " << c << " doesn't belong to the triangle" << std::endl;
	return (0);
}
