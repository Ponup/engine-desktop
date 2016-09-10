#pragma once

#include <string>
using std::string;

#include "Font.h"
#include "Dimension.h"
#include "Point.h"
#include "Surface.h"

class Text {

private:
	string text;
	Font *font;
	
	int alpha;

public:
	Text();
	Text( const string& text );
	Text( const string& text, Font *font );
	~Text();

	void setText( const string& text );
	string getText() const;
	void setFont( Font *font );
	Font *getFont() const;
	Dimension getDimension() const;

	void setAlpha( int alpha );

	SDL_Surface* toSDL();
	
	void draw( const Point &point, Surface *surface);
	void drawLines( const Point &point, const Dimension &dimension,
			Surface *surface);

	static void drawString( const string& text, const Point &point, Font *font,
			Surface *surface);
};

