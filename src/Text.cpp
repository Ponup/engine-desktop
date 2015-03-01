#include "Text.h"

#include <SDL.h>

#include "StringUtil.h"

Text::Text() {
	alpha = SDL_ALPHA_OPAQUE;
}

Text::Text(string text) {
	this->text = text;
	alpha = SDL_ALPHA_OPAQUE;
}

Text::Text(string text, Font *font) {
	this->text = text;
	this->font = font;
	alpha = SDL_ALPHA_OPAQUE;
}

Text::~Text() {
}

void Text::setText(string text) {
	this->text = text;
}

string Text::getText() const {
	return text;
}

void Text::setFont(Font *font) {
	this->font = font;
}

Font *Text::getFont() const {
	return font;
}

Dimension Text::getDimension() const {
	int width, height;
	if (TTF_SizeText(font->toSDL(), text.c_str(), &width, &height)) {
		fprintf(stderr, "%s\n", TTF_GetError());
	}

	return Dimension(width, height);
}

void Text::setAlpha(int alpha) {
	this->alpha = alpha;
}

void Text::draw( const Point &point, Surface *surface ) {
	SDL_Surface *fontSurface= NULL;
	Color color = font->getColor();
	switch (font->getStyle()) {
	case BLENDED:
		fontSurface
				= TTF_RenderUTF8_Blended(font->toSDL(), text.c_str(), color );
		break;
	case SOLID:
		fontSurface = TTF_RenderUTF8_Solid(font->toSDL(), text.c_str(), color );
		break;
	case SHADED:
	default: {
		SDL_Color bgColor = { 0, 0, 0 };
		fontSurface = TTF_RenderUTF8_Shaded(font->toSDL(), text.c_str(), color,
				bgColor);
	} break;
	}

	// @TODO
	if(fontSurface) {
		//SDL_SetAlpha(fontSurface, SDL_SRCALPHA, alpha);
		SDL_Rect dstRect = { point.x, point.y, 0, 0 };
		SDL_BlitSurface(fontSurface, NULL, surface->toSDL(), &dstRect);
		SDL_FreeSurface(fontSurface);
	}
}

void Text::drawLines(const Point &point, const Dimension &dimension,
		Surface *surface) {
	Point np = point;
	vector<string> tokens;
	StringUtil::tokenize(text, tokens, " ");
	const int lineSkip = TTF_FontLineSkip(font->toSDL());

	string testLine;
	string finalLine;
	Text * newText= new Text();
	newText->setFont(font);
	int width, height;
	//	while(!tokens.empty()) {
	bool left = true;
	for (unsigned int i = 0; i < tokens.size(); i++) {
		testLine += tokens.at(i) + " ";
		if (TTF_SizeText(font->toSDL(), testLine.c_str(), &width, &height)) {
			fprintf(stderr, "%s\n", TTF_GetError());
		}
		if ((unsigned)width < dimension.w) {
			finalLine = testLine;
			left = true;
		} else { // every time we reach the final, move the point
			left = false;
			newText->setText(finalLine.c_str());
			newText->draw(np, surface);
			testLine.clear();
			testLine = tokens.at(i) + " ";

			np.x = np.x;
			np.y = np.y + lineSkip;
		}
	}
	if (left) {
		newText->setText(finalLine.c_str());
		newText->draw(np, surface);
	}
}

void Text::drawString(string text, const Point &point, Font *font,
		Surface *surface) {
	Text t(text, font);
	t.draw(point, surface);
}
