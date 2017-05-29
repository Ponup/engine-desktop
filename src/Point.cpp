#include "Point.h"

#include <sstream>
using std::ostringstream;

const Point Point::Origin(0, 0);

Point Point::operator-(const Point& point) {
    return Point(x - point.x, y - point.y);
}

Point Point::operator+(const Point &point) {
    return Point(x + point.x, y + point.y);
}

Point Point::operator=(const Point &point) {
    x = point.x;
    y = point.y;
    return *this;
}

bool Point::operator==(const Point &point) {
    return ( x == point.x && y == point.y);
}

string Point::toString() const {
    ostringstream oss;
    oss << "Point [ x: " << x << ", y: " << y << " ]";
    return oss.str();
}

