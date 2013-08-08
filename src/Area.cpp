#include "Area.h"

void Area::setPoint(const Point &point) {
	this->point = point;
}

Point Area::getPoint() const {
	return point;
}

void Area::setDimension(const Dimension &dimension) {
	this->dimension = dimension;
}

Dimension Area::getDimension() const {
	return dimension;
}

bool Area::contains(short x, short y) const {
	return (
		x >= point.getX() &&
		x <= point.getX() + dimension.getWidth() &&
		y >= point.getY() &&
		y <= point.getY() + dimension.getHeight()
	);
}

SDL_Rect Area::toSDL() const {
	SDL_Rect rect;
	rect.x = point.getX();
	rect.y = point.getY();
	rect.w = dimension.getWidth();
	rect.h = dimension.getHeight();
	
	return rect;
}

const char *Area::toString() const {
	char *text = (char *)calloc(60, sizeof(char));
	if(!text) return NULL;

	sprintf(text, "Area [ x: %d, y: %d, width: %d, height: %d ]",
		point.getX(),
		point.getY(),
		dimension.getWidth(),
		dimension.getHeight()
	);
	
	return text;
}

