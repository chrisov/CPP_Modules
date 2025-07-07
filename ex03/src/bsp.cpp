#include "../inc/Point.hpp"

static Fixed crossProduct(Point a, Point b) {
    return a.getX() * b.getY() - a.getY() * b.getX();
}

static bool sameSign(Point p1, Point p2, Point a, Point b) {
    Fixed cp1 = crossProduct(b - a, p1 - a);
    Fixed cp2 = crossProduct(b - a, p2 - a);
    return (cp1 * cp2 > Fixed(0));
}
/**
 * @note Checks if the point p is inside the triangle (a,b,c).
 */
bool bsp(Point const a, Point const b, Point const c, Point const p) {
    return (sameSign(p, a, b, c) &&
            sameSign(p, b, a, c) &&
            sameSign(p, c, a, b));
}
