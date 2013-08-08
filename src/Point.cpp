#include "Point.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Point Point::operator-(const Point &point) {
	return Point(x - point.getX(), y - point.getY());
}

Point Point::operator+(const Point &point) {
	return Point(x + point.getX(), y + point.getY());
}

Point Point::operator=(const Point &point) {
	x = point.getX();
	y = point.getY();
	return *this;
}

bool Point::operator==(const Point &point) {
	return (x == point.x && y == point.y);
}

void Point::setX(short x) {
	this->x = x;
}

short Point::getX() const {
	return x;
}

void Point::setY(short y) {
	this->y = y;
}

short Point::getY() const {
	return y;
}

const char *Point::toString() const {
	char *text = (char *)calloc(30, sizeof(char));
	if(!text) return NULL;

	sprintf(text, "Point [ x: %d, y: %d ]", x, y);

	return text;
}

