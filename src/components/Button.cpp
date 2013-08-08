#include "components/Button.h"

Button::Button(const char *label_, Font *font_, const ButtonSkin *skinNormal_,
		const ButtonSkin *skinOver_) :
	skinNormal(*skinNormal_), skinOver(*skinOver_) {
	state = STATE_NORMAL;

	text = new Text(label_, font_);
	dimension = Dimension(skinNormal.leftSurf->getDimension().getWidth() + text->getDimension().getWidth() + skinNormal.rightSurf->getDimension().getWidth(), 50);
}

Button::~Button() {
	delete text;
}

Text *Button::getText() {
	return text;
}

void Button::setState(ButtonState state) {
	this->state = state;
}

ButtonState Button::getState() const {
	return state;
}

void Button::setPosition(Point position) {
	this->position = position;
}

Point Button::getPosition() const {
	return position;
}

Dimension Button::getDimension() const {
	return dimension;
}

void Button::draw(Surface *surface) {
	if(!surface) return;

	const ButtonSkin *skin = NULL;

	if(state == STATE_NORMAL)
		skin = &skinNormal;
	else
		skin = &skinOver;

	if(!skin) return;

	if(skin->leftSurf)
		surface->drawSurface(skin->leftSurf, getPosition());

	if(skin->centerSurf) {
		int textWidth = text->getDimension().getWidth();
		for (int x = 0; x < textWidth; x++) {
			surface->drawSurface(skin->centerSurf, getPosition()
					+ Point( 27 + x, 0));
		}
	}
	if(text)
		text->draw(getPosition() + Point(27, 12), surface);

	if(skin->rightSurf)
		surface->drawSurface(skin->rightSurf, getPosition() + Point( text->getDimension().getWidth() + 27, 0));
}
