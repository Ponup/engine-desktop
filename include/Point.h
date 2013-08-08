#ifndef POINT_H
#define POINT_H

/**
 * Indicates the position of an element on the screen.
 */
class Point {
private:
	short x;
	short y;

public:
	Point() : x(0), y(0) { }
	Point(const Point &point) : x(point.getX()), y(point.getY()) { }
	Point(short x_, short y_) : x(x_), y(y_) { }

	Point operator-(const Point &point);
	Point operator+(const Point &point);
	Point operator=(const Point &point);
	bool operator==(const Point &point);

	void setX(short x);
	short getX() const;
	void setY(short y);
	short getY() const;

	const char *toString() const;
};

#endif

