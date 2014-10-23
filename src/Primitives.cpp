#include "Primitives.h"

#include "MathUtil.h"

void Primitives::drawPoint(SDL_Surface * screen, const Point & point, const Color & color_) {
    Uint32 color = SDL_MapRGB(screen->format, color_.r, color_.g, color_.b);
    Uint16 * bufp = (Uint16 *)screen->pixels + point.y *screen->pitch/2 + point.x;
    *bufp = color;
}

void Primitives::drawPixel(Surface * surface, const Point & point, const Color & color_) {
	SDL_Surface * screen = surface->toSDL();
    if(SDL_MUSTLOCK(screen)) {
		if(SDL_LockSurface(screen) < 0) {
            return;
        }
    }
	drawPoint(screen, point, color_);
    if(SDL_MUSTLOCK(screen)) {
        SDL_UnlockSurface(screen);
    }
    //SDL_UpdateRect(screen, point.x, point.y, 1, 1);
}	

void Primitives::drawLine(Surface * surface, const Point & from, const Point & to, const Color & color) {
	SDL_Surface * screen = surface->toSDL();
    if(SDL_MUSTLOCK(screen)) {
		if(SDL_LockSurface(screen) < 0) {
            return;
        }
    }
    
    unsigned int distance = MathUtil::calculateDistance(from, to);
    double degrees = MathUtil::calculateDegrees(from, to);
	for(unsigned int radius = 0; radius < distance; radius++) {
		double radians = MathUtil::degree2radian(degrees);
		int x = int(radius * cos(radians));
		int y = int(radius * sin(radians));
		Point point;
		point.x = from.x + x;
		point.y = from.y + y;
		drawPoint(screen, point, color);
	}
	
    if(SDL_MUSTLOCK(screen)) {
        SDL_UnlockSurface(screen);
    }
}
