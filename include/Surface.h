#pragma once

#include "Area.h"
#include "Color.h"

/**
 * This class manages the logic and information of a canvas.
 */
class Surface {

protected:
	SDL_Surface *surface;

public:
	Surface();
	Surface(SDL_Surface *surface);
	Surface(Surface *surface, const Dimension &dimension);
	Surface(const char *path, bool hasAlphaChannel = false);
	virtual ~Surface();

	void load(const char *path, bool hasAlphaChannel = false);

	void optimize();
	Dimension getDimension() const;
	void clean();
	void clean(const Color &color);
	void setTransparentColor(const Color &color);
	void drawSurface( Surface* image, const Point &point = Point::Origin );

	void updateArea(const Point &point, const Dimension &dimension);
	void updateArea(const Area &area);

	Surface *getArea( const Point&, const Dimension& );
	Surface *getArea( const Area& area );

	void transform( double angle, double zoom = 1, int smooth = 1 );

	void setOpacity(Uint8 opacity);
	SDL_Surface *toSDL();
};

