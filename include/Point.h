#pragma once

#include <SDL_rect.h>

#include <string>
using std::string;

/**
 * Indicates the position of an element on a 2D space.
 */
class Point : public SDL_Point {

public:
	const static Point Origin;

	Point() { x = y = 0; }
	Point( const Point& point ) { x = point.x; y = point.y; }
	Point( short x_, short y_ ) { x = x_; y = y_; }

	Point operator-( const Point& point );
	Point operator+( const Point& point );
	Point operator=( const Point& point );
	bool operator==( const Point& point );

	string toString() const;
};

