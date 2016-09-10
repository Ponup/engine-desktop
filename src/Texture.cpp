#include "Texture.h"

#include <SDL_image.h>

Kangaroo::Texture::Texture(SDL_Renderer* renderer, const string& path) {
	internal = IMG_LoadTexture(renderer, path.c_str());
	init();
}

Kangaroo::Texture::Texture(SDL_Renderer* renderer, SDL_Surface* surface) {
	internal = SDL_CreateTextureFromSurface(renderer, surface);
	init();
}

void Kangaroo::Texture::init() {
	if (SDL_QueryTexture(internal, NULL, NULL, &width, &height) != 0) {
		// Log warning
	}
}

SDL_Texture* Kangaroo::Texture::getInternal() {
	return internal;
}

int Kangaroo::Texture::getWidth() const {
	return width;
}

int Kangaroo::Texture::getHeight() const {
	return height;
}

