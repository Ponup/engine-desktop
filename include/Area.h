#ifndef AREA_H
#define AREA_H

#include <SDL.h>

#include "Point.h"
#include "Dimension.h"

/**
 * Contains information about a delimited area, indicated by a dimension (width, height), and its position.
 * 
 * @see Point
 * @see Dimension
 */
class Area{

private :
	Point point;
	Dimension dimension;

public:
	Area() { }
	Area(unsigned int x, unsigned int y, unsigned int width, unsigned int height) : point(x, y), dimension(width, height) { }
	Area(const Point &point_, const Dimension &dimension_) : point(point_), dimension(dimension_) { }

	void setPoint(const Point &point);
	Point getPoint() const;

	void setDimension(const Dimension &dimension);
	Dimension getDimension() const;
	
	bool contains(short x, short y) const;
	
	SDL_Rect toSDL() const;
	const char *toString() const;
};

#endif

