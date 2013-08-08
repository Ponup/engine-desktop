#ifndef BUTTON_H_
#define BUTTON_H_

#include "Point.h"
#include "Dimension.h"
#include "Surface.h"
#include "Font.h"
#include "Text.h"

#include "components/skins/ButtonSkin.h"

typedef enum {
	STATE_NORMAL,
	STATE_OVER
} ButtonState;

class Button {

private:
	Text *text;

	ButtonState state;

	const ButtonSkin skinNormal;
	const ButtonSkin skinOver;

	Point position;
	Dimension dimension;

public:
	Button(const char *label_, Font *font_, const ButtonSkin *skinNormal,
			const ButtonSkin *skinOver);
	virtual ~Button();

	Text *getText();

	void setState(ButtonState state);
	ButtonState getState() const;

	void setPosition(Point position);
	Point getPosition() const;

	Dimension getDimension() const;

	void draw(Surface *surface);
};

#endif
