#include "Font.h"

#include <stdio.h>

#include <stdexcept>
using std::runtime_error;

Font::Font() {
}

Font::Font(const char *fontPath, unsigned int size) {
	load(fontPath, size);
}

void Font::load(const char *fontPath, unsigned int size) {
	this->path = fontPath;
	this->size = size;

	font = TTF_OpenFont(fontPath, size);
	if(font == NULL) {
		char *errorMsg = TTF_GetError();
		fprintf(stderr, "%s\n", errorMsg);
		fflush(stderr);
		throw std::runtime_error(errorMsg);
	}
	style = BLENDED;
}

Font::Font(const Font &font) {
	load(font.getPath(), font.getSize());

	this->style = font.getStyle();
	this->color = font.getColor();
}

Font::~Font() {
	if(font != NULL) {
		TTF_CloseFont(font);
		font = NULL;
	}
}

const char *Font::getPath() const {
	return path;
}

int Font::getSize() const {
	return size;
}

void Font::setStyle(FontStyle style) {
	this->style = style;
}

FontStyle Font::getStyle() const {
	return style;	
}

void Font::setColor(const Color &color) {
	this->color = color;
}

Color Font::getColor() const {
	return color;
}

unsigned int Font::getLineSkip() const {
	return TTF_FontLineSkip(font);
}

TTF_Font *Font::toSDL() {
	return font;	
}

