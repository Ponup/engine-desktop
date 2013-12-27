#include "Point.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Point Point::operator-( const Point& point ) {
	return Point( x - point.x, y - point.y );
}

Point Point::operator+( const Point &point ) {
	return Point( x + point.x, y + point.y );
}

Point Point::operator=( const Point &point ) {
	x = point.x;
	y = point.y;
	return *this;
}

bool Point::operator==( const Point &point ) {
	return ( x == point.x && y == point.y );
}

const char* Point::toString() const {
	char* text = (char*)calloc( 30, sizeof( char ) );
	if( !text ) return NULL;

	sprintf( text, "Point [ x: %d, y: %d ]", x, y );

	return text;
}

