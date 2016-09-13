#include "TextUtils.h"

#include "StringUtil.h"

#include <vector>
#include <exception>

using std::vector;
using std::runtime_error;

void Kangaroo::TextUtils::drawLines(Renderer* renderer, const Text& text, const Point& position, const Dimension& containerDimension) const {
	Point nextPosition = position;
	vector<string> tokens;
	StringUtil::tokenize(text.getText(), tokens, " ");
	Font* font = text.getFont();
	const int lineSkip = TTF_FontLineSkip(font->toSDL());

	string testLine;
	string finalLine;
	Text singleLineText;
	singleLineText.setFont(font);
	int width, height;

	bool left = true;
	for (unsigned int i = 0; i < tokens.size(); i++) {
		testLine += tokens.at(i) + " ";
		if (TTF_SizeText(font->toSDL(), testLine.c_str(), &width, &height)) {
			throw runtime_error(TTF_GetError());
		}
		if ((unsigned)width < containerDimension.w) {
			finalLine = testLine;
			left = true;
		}
		else { // every time we reach the final, move the point
			left = false;
			singleLineText.setText(finalLine.c_str());
			renderer->drawText(&singleLineText, nextPosition);
			testLine.clear();
			testLine = tokens.at(i) + " ";

			nextPosition.x = nextPosition.x;
			nextPosition.y = nextPosition.y + lineSkip;
		}
	}
	if (left) {
		singleLineText.setText(finalLine.c_str());
		renderer->drawText(&singleLineText, nextPosition);
	}
}