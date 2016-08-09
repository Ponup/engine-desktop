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
	//	if( nullptr != texture )
	//		SDL_DestroyTexture( texture );
	SDL_DestroyWindow(window);
}

void Window::drawSurface(Surface * image, const Point &point) {
	if (nullptr == image)
		return;

	SDL_Surface* imageSurf = image->toSDL();
	if (imageSurf == nullptr) {
		return;
	}

	//SDL_Rect rectDst = { point.x, point.y, 0, 0 };
	SDL_Rect rectSrc;

	rectSrc.x = rectSrc.y = 0;
	rectSrc.w = imageSurf->w;
	rectSrc.h = imageSurf->h;

	//SDL_BlitSurface(imageSurf, &rectSrc, surface, &rectDst);

	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, imageSurf);

	//	SDL_RenderClear( renderer );
	//SDL_RenderCopy( renderer, texture, &rectSrc, &rectDst);
	SDL_RenderCopy(renderer, texture, nullptr, nullptr);
	SDL_DestroyTexture(texture);
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

void Window::flip() {
	SDL_UpdateTexture(texture, nullptr, surface->pixels, surface->pitch);
	SDL_RenderCopy(renderer, texture, nullptr, nullptr);
	SDL_RenderPresent(renderer);
}

SDL_Window* Window::toSDL() {
	return window;
}

SDL_Surface* Window::getSurface(void) {
	return SDL_GetWindowSurface(window);
}
