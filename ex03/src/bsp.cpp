#include "../inc/Point.hpp"

static float crossProduct(Point a, Point b) {
	Fixed	res;

	res = a.getX() * b.getY() - a.getY() * b.getX();
    return (res.toFloat());
}

static bool sameSign(Point p1, Point p2, Point a, Point b) {
    float cp1;
    float cp2;

    cp1 = crossProduct(b - a, p1 - a);
    cp2 = crossProduct(b - a, p2 - a);
    return (cp1 * cp2 > 0);
}

bool bsp(Point const a, Point const b, Point const c, Point const p) {
	return (sameSign(p, a, b, c) && sameSign(p, b, a, c) && sameSign(p, c, a, b));
}