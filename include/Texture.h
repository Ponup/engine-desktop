#pragma once

#include <SDL.h>

#include <string>
using std::string;

namespace Kangaroo {

	class Texture {

		SDL_Texture* internal;
		int width, height;

		void init();

	public:
		Texture(SDL_Renderer* renderer, const string& path);
		Texture(SDL_Renderer* renderer, SDL_Surface* surface);
		SDL_Texture* getInternal();

		int getWidth() const;
		int getHeight() const;
	};
}
