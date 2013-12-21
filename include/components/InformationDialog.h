#ifndef INFORMATION_DIALOG_H
#define INFORMATION_DIALOG_H

#include "components/AbstractDialog.h"
#include "components/Button.h"
#include "SensitiveAreas.h"
#include "Font.h"
#include "Surface.h"
#include "Point.h"
#include "Dimension.h"

class InformationDialog : public AbstractDialog {
	
private:
	SensitiveAreas sensAreas;
	bool quit;

	Font *font;

	Surface *screen;
	Surface *window;
	Surface *backup;

	Button *button;

	Point windowPosition;
	Dimension windowDimension;

	void update();

public:
	InformationDialog(Surface *screen, string message);
	~InformationDialog();

	void show();
	void handleEvents(SDL_Event e);
};

#endif

