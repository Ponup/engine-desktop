#ifndef TEXT_H
#define TEXT_H

#include "Surface.h"
#include "Font.h"
#include "Dimension.h"
#include "Point.h"

class Text {

private:
	char *text;
	Font *font;
	
	int alpha;

public:
	Text();
	Text(const char *text);
	Text(const char *text, Font *font);
	~Text();

	void setText(const char *text);
	char *getText() const;
	void setFont(Font *font);
	Font *getFont() const;
	Dimension getDimension() const;

	void setAlpha(int alpha);
	
	void draw(const Point &point, Surface *surface);
	void drawLines(const Point &point, const Dimension &dimension,
			Surface *surface);

	static void drawString(const char *txt, const Point &point, Font *font,
			Surface *surface);
};

#endif
