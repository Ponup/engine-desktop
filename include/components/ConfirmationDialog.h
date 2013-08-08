#ifndef CONFIRMATION_DIALOG_H
#define CONFIRMATION_DIALOG_H

#include "components/AbstractDialog.h"
#include "components/Button.h"
#include "SensitiveAreas.h"
#include "Font.h"
#include "Surface.h"
#include "Point.h"
#include "Dimension.h"

class ConfirmationDialog : public AbstractDialog {
	
private:
	SensitiveAreas sensAreas;
	int currentOption;
	int selected;
	bool quit;

	Font font;

	Surface *screen;
	Surface *backup;
	Surface *window;

	Button *buttons[2];

	Point windowPosition;
	Dimension windowDimension;

	void update();

public:
	ConfirmationDialog(Surface *screen, const char *message);
	~ConfirmationDialog();

	int showGetSelected();
	void handleEvents(SDL_Event e);
};

#endif

