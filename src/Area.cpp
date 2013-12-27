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
		x >= point.x &&
		x <= point.x + dimension.w &&
		y >= point.y &&
		y <= point.y + dimension.h
	);
}

SDL_Rect Area::toSDL() const {
	SDL_Rect rect;
	rect.x = point.x;
	rect.y = point.y;
	rect.w = dimension.w;
	rect.h = dimension.h;
	
	return rect;
}

const char *Area::toString() const {
	char *text = (char *)calloc(60, sizeof(char));
	if(!text) return NULL;

	sprintf(text, "Area [ x: %d, y: %d, width: %d, height: %d ]",
		point.x,
		point.y,
		dimension.w,
		dimension.h
	);
	
	return text;
}

