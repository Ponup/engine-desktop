#pragma once

#include <string>
using std::string;

#include "Surface.h"

/**
 * This class creates a Window/Frame object and can be handled as a Surface.
 * 
 * @see Surface
 */
class Window : public Surface {

private:
	string title;
	string iconPath;
	unsigned int width;
	unsigned int height;
	bool fullScreen;

	void defineSurface();

public:
	const static int FLAGS_WINDOW;
	const static int FLAGS_FULLSCREEN;

	Window( const string& title, unsigned int width, unsigned int height );
	Window( const string& title, unsigned int width, unsigned int height, const string& iconPath, bool fullScreen );
	void flip();

	/**
	 * Switch between windowed and fullscreen modes.
	 */
	void toggleFullScreen();
};

