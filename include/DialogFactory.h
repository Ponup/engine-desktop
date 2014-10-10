#pragma once

#include "Surface.h"

class DialogFactory {

public:
	static int showConfirmationDialog(Surface *screen, const char *message);
	static void showInformationDialog(Surface *screen, const char *message);
	static char *showInputDialog(Surface *screen, const char *message);
};

