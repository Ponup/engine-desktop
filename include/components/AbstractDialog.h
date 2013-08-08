#ifndef ABSTRACTDIALOG_H
#define ABSTRACTDIALOG_H

#include <SDL.h>

class AbstractDialog {
	public:
		enum {
			DIALOG_OK = 0,
			DIALOG_CANCEL,
			DIALOG_YES,
			DIALOG_NO
		};
		virtual ~AbstractDialog() {}
		
		virtual void update() = 0;
		virtual void handleEvents(SDL_Event e) = 0;
};

#endif

