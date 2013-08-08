#include "components/skins/ButtonSkin.h"

ButtonSkin::ButtonSkin(const char *l, const char *c, const char *r) {
	leftSurf = new Surface(l);
	centerSurf = new Surface(c);
	rightSurf = new Surface(r);
}

ButtonSkin::ButtonSkin(const ButtonSkin &buttonSkin) {
	leftSurf = new Surface(buttonSkin.leftSurf->toSDL());
	centerSurf = new Surface(buttonSkin.centerSurf->toSDL());
	rightSurf = new Surface(buttonSkin.rightSurf->toSDL());
}

ButtonSkin::~ButtonSkin() {
	delete leftSurf;
	delete centerSurf;
	delete rightSurf;
}
