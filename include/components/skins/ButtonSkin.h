#ifndef BUTTONSKIN_H_
#define BUTTONSKIN_H_

#include <Surface.h>

class ButtonSkin {

public:
	ButtonSkin(const char *l, const char *c, const char *r);
	ButtonSkin(const ButtonSkin &buttonSkin);
	~ButtonSkin();

	Surface *leftSurf;
	Surface *centerSurf;
	Surface *rightSurf;
};

#endif
