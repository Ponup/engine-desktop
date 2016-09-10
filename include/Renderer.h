#pragma once

#include "SDL.h"

#include "Point.h"
#include "Texture.h"
#include "Text.h"

using Kangaroo::Texture;

namespace Kangaroo {

	class Renderer {

		SDL_Renderer* internal;

	public:
		Renderer(SDL_Renderer* renderer);

		void drawTexture(Texture* texture, const Point& pos = Point::Origin);
		void drawText(Text* text, const Point& pos = Point::Origin);
		void present();
	};
}