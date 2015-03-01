#include "components/ConfirmationDialog.h"

#include <SDL2_gfxPrimitives.h>

#include "FontManager.h"
#include "SurfaceUtil.h"

ConfirmationDialog::ConfirmationDialog(Window *screen_, const string& message_) : screen(screen_), message(message_) {
}

ConfirmationDialog::~ConfirmationDialog() {}

int ConfirmationDialog::showGetSelected() {
	const SDL_MessageBoxButtonData buttons[] = {
		{ SDL_MESSAGEBOX_BUTTON_RETURNKEY_DEFAULT, DIALOG_YES, "Yes" },
		{ SDL_MESSAGEBOX_BUTTON_ESCAPEKEY_DEFAULT, DIALOG_NO, "No" },
	};
	const SDL_MessageBoxData messageboxdata = {
		SDL_MESSAGEBOX_INFORMATION, /* .flags */
		screen->toSDL(), /* .window */
		"Confirm", /* .title */
		message.c_str(), /* .message */
		SDL_arraysize(buttons), /* .numbuttons */
		buttons, /* .buttons */
		colorScheme /* .colorScheme */
	};
	int buttonid;
	if (SDL_ShowMessageBox(&messageboxdata, &buttonid) < 0) {
		return DIALOG_YES;
	}
	return buttonid;
}

