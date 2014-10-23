#pragma once

#include <SDL2/SDL.h>

#include "Surface.h"
#include "Point.h"
#include "Color.h"

class Primitives {
	private:
		static void drawPoint(SDL_Surface * screen, const Point & point, const Color & color);
		
	public:
		static void drawPixel(Surface * surface, const Point & point, const Color & color);
		static void drawLine(Surface * surface, const Point & from, const Point & to, const Color & color);
};

