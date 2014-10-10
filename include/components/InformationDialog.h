#pragma once

#include "components/AbstractDialog.h"
#include "components/Button.h"
#include "SensitiveAreas.h"
#include "Font.h"
#include "Surface.h"
#include "Point.h"
#include "Dimension.h"
#include "Window.h"

class InformationDialog : public AbstractDialog {
	
private:
	SensitiveAreas sensAreas;
	bool quit;

	Font *font;

	Window *screen;
	Surface *window;
	Surface *backup;

	Button *button;

	Point windowPosition;
	Dimension windowDimension;

	void update();

public:
	InformationDialog(Window *screen, string message);
	~InformationDialog();

	void show();
	void handleEvents(SDL_Event e);
};

