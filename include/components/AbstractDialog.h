#pragma once

#include <SDL.h>

class AbstractDialog {
	public:
		enum {
			DIALOG_OK = 0,
			DIALOG_CANCEL,
			DIALOG_YES,
			DIALOG_NO
		};
		SDL_MessageBoxColorScheme *colorScheme = new SDL_MessageBoxColorScheme {
			{ /* .colors (.r, .g, .b) */
				/* [SDL_MESSAGEBOX_COLOR_BACKGROUND] */
				{ 255, 0, 0 },
				/* [SDL_MESSAGEBOX_COLOR_TEXT] */
				{ 0, 255, 0 },
				/* [SDL_MESSAGEBOX_COLOR_BUTTON_BORDER] */
				{ 255, 255, 0 },
				/* [SDL_MESSAGEBOX_COLOR_BUTTON_BACKGROUND] */
				{ 0, 0, 255 },
				/* [SDL_MESSAGEBOX_COLOR_BUTTON_SELECTED] */
				{ 255, 0, 255 }
			}
		};
		
		virtual ~AbstractDialog() {}
};

