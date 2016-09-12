#pragma once

#include <string>
using std::string;

#include "AbstractDialog.h"
#include "Window.h"

class ConfirmationDialog : public AbstractDialog {

	Window *screen;
	string message;

public:
	ConfirmationDialog(Window *screen, const string& message_);
	~ConfirmationDialog();

	int showGetSelected();
};

