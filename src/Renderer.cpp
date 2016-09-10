#include "Renderer.h"

Kangaroo::Renderer::Renderer(SDL_Renderer* renderer) : internal(renderer) {

}

void Kangaroo::Renderer::drawTexture(Texture* texture, const Point& pos) {
	SDL_Rect srcRect = { 0, 0, texture->getWidth(), texture->getHeight() };
	SDL_Rect dstRect = { pos.x, pos.y, texture->getWidth(), texture->getHeight() };
	SDL_RenderCopy(internal, texture->getInternal(), &srcRect, &dstRect);
}

void Kangaroo::Renderer::drawText(Text* text, const Point& pos) {
	Texture texture(internal, text->toSDL());
	drawTexture(&texture, pos);
}

void Kangaroo::Renderer::present() {
	SDL_RenderPresent(internal);
}
