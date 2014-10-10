#pragma once

#include <SDL.h>

/**
 * Color definition, taking four parameters (r, g, b and a channel)
 */
class Color {
	public:
		unsigned char r;
		unsigned char g;
		unsigned char b;
		unsigned char a;		

		Color();
		Color( unsigned char r, unsigned char g, unsigned char b );
		Color( unsigned char r, unsigned char g, unsigned char b, unsigned char a );
		
		Uint32 toSDL( SDL_Surface* surface ) const;
		SDL_Color toSDL() const;
};

