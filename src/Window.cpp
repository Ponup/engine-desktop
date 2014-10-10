#include "Window.h"

#include <stdio.h>
#include <SDL.h>
#include <SDL_image.h>

const int Window::FLAGS_WINDOW = SDL_DOUBLEBUF | SDL_HWSURFACE;
const int Window::FLAGS_FULLSCREEN = SDL_DOUBLEBUF | SDL_HWSURFACE | SDL_FULLSCREEN;

Window::Window( const string& title, unsigned int width, unsigned int height) {
	*this = Window(title, width, height, NULL, false);
}

Window::Window( const string& title_, unsigned int width_, unsigned int height_, const string& iconPath_, bool fullScreen_) :
	title(title_), iconPath(iconPath_), width(width_), height(height_), fullScreen(fullScreen_) {

	defineSurface();
}

void Window::toggleFullScreen() {
	fullScreen = !fullScreen;
	defineSurface();
}

void Window::defineSurface() {
	int flags = (fullScreen ? Window::FLAGS_FULLSCREEN : Window::FLAGS_WINDOW);

	SDL_WM_SetCaption(title.c_str(), title.c_str());

	if (!iconPath.empty()) {
		SDL_Surface *icon = IMG_Load(iconPath.c_str());
		if (icon != NULL) {
			SDL_WM_SetIcon(icon, NULL);
			SDL_FreeSurface(icon);
		}
	}

	surface = SDL_SetVideoMode(width, height, 24, flags);
	if (surface == NULL) {
		fprintf(stderr, "%s\n", SDL_GetError());
	}
}

void Window::flip() {
	SDL_Flip( surface );
}


