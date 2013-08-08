#include "Dimension.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Dimension::Dimension(const Dimension &dimension) {
	width = dimension.getWidth();
	height = dimension.getHeight();
}

void Dimension::setWidth(unsigned short width) {
	this->width = width;
}

unsigned short Dimension::getWidth() const {
	return width;
}

void Dimension::setHeight(unsigned short height) {
	this->height = height;
}

unsigned short Dimension::getHeight() const {
	return height;
}

const char *Dimension::toString() const {
	char *text = (char *)calloc(50, sizeof(char));
	if(!text) return NULL;

	sprintf(text, "Dimension [ width: %d, height: %d ]", width, height);
	
	return text;
}

