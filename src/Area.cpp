#include "Area.h"

#include <sstream>
using std::ostringstream;

void Area::setPoint(const Point &point) {
	x = point.x;
	y = point.y;
}

Point Area::getPoint() const {
	return Point( x, y );
}

void Area::setDimension(const Dimension &dimension) {
	w = dimension.w;
	h = dimension.h;
}

Dimension Area::getDimension() const {
	return Dimension( w, h );
}

bool Area::contains( short x_, short y_ ) const {
	return (
		x_ >= x &&
		x_ <= x + w &&
		y_ >= y &&
		y_ <= y + h
	);
}

string Area::toString() const {
	ostringstream oss;
	oss << "Area [ x: " << x << " y: " << y << ", width: " << w << ", height: " << h << " ]";
	return oss.str();
}

