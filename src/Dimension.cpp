#include "Dimension.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Dimension::Dimension( const Dimension& dimension ) {
	w = dimension.w;
	h = dimension.h;
}

const char* Dimension::toString() const {
	char* text = (char*)calloc( 50, sizeof( char ) );
	if( !text ) return NULL;

	sprintf( text, "Dimension [ w: %d, h: %d ]", w, h );
	
	return text;
}

