#include "Window.h"

#include <stdio.h>
#include <SDL.h>
#include <SDL_image.h>

const int Window::FLAGS_WINDOW= SDL_DOUBLEBUF | SDL_HWSURFACE;
const int Window::FLAGS_FULLSCREEN= SDL_DOUBLEBUF | SDL_HWSURFACE | SDL_FULLSCREEN;

Window::Window(string title, unsigned int width, unsigned int height) {
	*this = Window(title, width, height, NULL, false);
}

Window::Window(string title_, unsigned int width_, unsigned int height_,
		const char * iconPath, bool fullScreen_) :
	title(title_), width(width_), height(height_), fullScreen(fullScreen_) {
	SDL_WM_SetCaption(title_.c_str(), title_.c_str());

	if (iconPath != NULL) {
		SDL_Surface *icon = IMG_Load(iconPath);
		if (icon != NULL) {
			SDL_WM_SetIcon(icon, NULL);
		}
	}

	defineSurface();
}

void Window::toggleFullScreen() {
	fullScreen = !fullScreen;
	defineSurface();
}

void Window::defineSurface() {
	int flags = (fullScreen ? Window::FLAGS_FULLSCREEN : Window::FLAGS_WINDOW);

	surface = SDL_SetVideoMode(width, height, 24, flags);
	if (surface == NULL) {
		fprintf(stderr, "%s\n", SDL_GetError());
	}
}
