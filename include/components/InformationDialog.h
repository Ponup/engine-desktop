#pragma once

#include <string>
using std::string;

#include "AbstractDialog.h"
#include "Window.h"

class InformationDialog : public AbstractDialog {

	Window *screen;
	string message;

public:
	InformationDialog(Window *screen, const string& message_);
	~InformationDialog();

	void show();
};

