#include "Window.h"

#include <stdio.h>
#include <SDL.h>
#include <SDL_image.h>

const int Window::FLAGS_WINDOW = SDL_WINDOW_SHOWN;
const int Window::FLAGS_FULLSCREEN = SDL_WINDOW_SHOWN | SDL_WINDOW_FULLSCREEN;

SDL_Renderer* Window::renderer = nullptr;
SDL_Texture* Window::texture = nullptr;

Window::Window(const string& title, unsigned int width, unsigned int height) {
	*this = Window(title, width, height, nullptr, false);
}

Window::Window(const string& title_, unsigned int width_, unsigned int height_, const string& iconPath_, bool fullScreen_) :
title(title_), iconPath(iconPath_), width(width_), height(height_), fullScreen(fullScreen_) {

	defineSurface();
}

Window::~Window() {
	SDL_DestroyWindow(window);
}

void Window::toggleFullScreen() {
	fullScreen = !fullScreen;
	SDL_SetWindowFullscreen(window, fullScreen ? SDL_WINDOW_FULLSCREEN : 0);
}

void Window::defineSurface() {
	int flags = (fullScreen ? Window::FLAGS_FULLSCREEN : Window::FLAGS_WINDOW);

	window = SDL_CreateWindow(title.c_str(),
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		width,
		height,
		flags);

	if (!iconPath.empty()) {
		SDL_Surface *icon = IMG_Load(iconPath.c_str());
		if (icon != nullptr) {
			SDL_SetWindowIcon(window, icon);
			SDL_FreeSurface(icon);
		}
	}


	//	surface = SDL_GetWindowSurface( window );

	renderer = SDL_CreateRenderer(window, -1, 0);
	//	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");  // make the scaled rendering look smoother.
	//	SDL_RenderSetLogicalSize(renderer, width, height);
}

Dimension Window::getDimension() const {
	return Dimension(width, height);
}

SDL_Window* Window::toSDL() {
	return window;
}

SDL_Surface* Window::getSurface(void) {
	return SDL_GetWindowSurface(window);
}

//SDL_UpdateWindowSurface