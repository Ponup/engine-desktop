#pragma once

#include <string>
using std::string;

#include "Surface.h"
#include "Font.h"
#include "Dimension.h"
#include "Point.h"

class Text {

private:
	string text;
	Font *font;
	
	int alpha;

public:
	Text();
	Text(string text);
	Text(string text, Font *font);
	~Text();

	void setText(string text);
	string getText() const;
	void setFont(Font *font);
	Font *getFont() const;
	Dimension getDimension() const;

	void setAlpha(int alpha);
	
	void draw(const Point &point, Surface *surface);
	void drawLines(const Point &point, const Dimension &dimension,
			Surface *surface);

	static void drawString(string text, const Point &point, Font *font,
			Surface *surface);
};

