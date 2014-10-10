#pragma once

#include <string>
using std::string;

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
	ConfirmationDialog(Surface *screen, string message);
	~ConfirmationDialog();

	int showGetSelected();
	void handleEvents(SDL_Event e);
};

