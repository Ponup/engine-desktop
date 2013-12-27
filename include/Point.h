#ifndef POINT_H
#define POINT_H

/**
 * Indicates the position of an element on the screen.
 */
class Point {
public:
	short x;
	short y;

	Point() : x( 0 ), y( 0 ) {}
	Point( const Point& point ) : x( point.x ), y( point.y ) {}
	Point( short x_, short y_ ) : x( x_ ), y( y_ ) {}

	Point operator-( const Point& point );
	Point operator+( const Point& point );
	Point operator=( const Point& point );
	bool operator==( const Point& point );

	const char* toString() const;
};

#endif

