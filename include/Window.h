#pragma once

#include <SDL2/SDL.h>

#include <string>
using std::string;

#include "Surface.h"

/**
 * This class creates a Window/Frame object and can be handled as a Surface.
 * 
 * @see Surface
 */
class Window  {

private:
	string title;
	string iconPath;
	unsigned int width;
	unsigned int height;
	bool fullScreen;

	SDL_Surface* surface;
	SDL_Window* window;

	void defineSurface();

public:
	static SDL_Renderer* renderer;
	static SDL_Texture* texture;


public:
	const static int FLAGS_WINDOW;
	const static int FLAGS_FULLSCREEN;

	Window( const string& title, unsigned int width, unsigned int height );
	Window( const string& title, unsigned int width, unsigned int height, const string& iconPath, bool fullScreen );
	~Window();

	void drawSurface( Surface* image, const Point &point = Point::Origin );
	Dimension getDimension() const;
	SDL_Window* toSDL();
	void flip();

	/**
	 * Switch between windowed and fullscreen modes.
	 */
	void toggleFullScreen();
};

