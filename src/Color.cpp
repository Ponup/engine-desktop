#include "Color.h"

Color::Color() : r( 0 ), g( 0 ), b( 0 ), a( SDL_ALPHA_OPAQUE ) {
}

Color::Color( unsigned char r_, unsigned char g_, unsigned char b_ ) : 
	r( r_ ), g( g_ ), b( b_ ), a( SDL_ALPHA_OPAQUE ) {
}

Color::Color( unsigned char r_, unsigned char g_, unsigned char b_, unsigned char a_ ) : 
	r( r_ ), g( g_ ), b( b_ ), a( a_ ) {
}

Uint32 Color::toSDL( SDL_Surface* surface ) const {
	return SDL_MapRGB( surface->format, r, g, b );
}

SDL_Color Color::toSDL() const {
	SDL_Color color = { r, g, b, a };
	return color;
}
