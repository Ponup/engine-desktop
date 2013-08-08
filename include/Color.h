#ifndef COLOR_H
#define COLOR_H

#include <SDL.h>

/**
 * Color definition, taking four parameters (red, green, blue and alpha channel)
 */
class Color {
	private:
		unsigned char red;
		unsigned char green;
		unsigned char blue;
		unsigned char alpha;		
		
	public:
		Color();
		Color(unsigned char red, unsigned char green, unsigned char blue);
		Color(unsigned char red, unsigned char green, unsigned char blue, unsigned char alpha);
		
		unsigned char getAlpha() const; 
		void setAlpha(unsigned char alpha);
		unsigned char getRed() const;
		void setRed(unsigned char red);
		unsigned char getGreen() const;
		void setGreen(unsigned char green);
		unsigned char getBlue() const;
		void setBlue(unsigned char blue);
		
		Uint32 toSDL(SDL_Surface *surface) const;
		SDL_Color toSDL() const;
};

#endif
