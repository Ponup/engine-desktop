#include "Color.h"

Color::Color() : red(0), green(0), blue(0), alpha(SDL_ALPHA_OPAQUE) {
}

Color::Color(unsigned char red_, unsigned char green_, unsigned char blue_) : 
	red(red_), green(green_), blue(blue_), alpha(SDL_ALPHA_OPAQUE) {
}

Color::Color(unsigned char red_, unsigned char green_, unsigned char blue_, unsigned char alpha_) : 
	red(red_), green(green_), blue(blue_), alpha(alpha_) {
}

unsigned char Color::getRed() const {
	return red;
}

void Color::setRed(unsigned char red) {
	this->red = red;
}

unsigned char Color::getGreen() const {
	return green;
}

void Color::setGreen(unsigned char green) {
	this->green = green;
}

unsigned char Color::getBlue() const {
	return blue;
}

void Color::setBlue(unsigned char blue) {
	this->blue = blue;
}

unsigned char Color::getAlpha() const {
	return alpha;
}

void Color::setAlpha(unsigned char alpha) {
	this->alpha = alpha;
}

Uint32 Color::toSDL(SDL_Surface *surface) const {
	return SDL_MapRGB(surface->format, red, green, blue);
}

SDL_Color Color::toSDL() const {
	SDL_Color color = {
		red,
		green,
		blue,
		alpha
	};
	
	return color;
}
