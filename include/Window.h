#ifndef WINDOW_H
#define WINDOW_H

#include "Surface.h"

/**
 * This class creates a Window/Frame object and can be handled as a Surface.
 * 
 * @see Surface
 */
class Window : public Surface {

private:
	const char *title;
	unsigned int width;
	unsigned int height;
	bool fullScreen;

	void defineSurface();

public:
	const static int FLAGS_WINDOW;
	const static int FLAGS_FULLSCREEN;

	Window(const char *title, unsigned int width, unsigned int height);
	Window(const char *title, unsigned int width, unsigned int height,
			const char *iconPath, bool fullScreen);

	/**
	 * Switch between windowed and fullscreen modes.
	 */
	void toggleFullScreen();
};

#endif
