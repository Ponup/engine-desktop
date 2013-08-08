#include "Surface.h"

#include <SDL_image.h>

#include "StringUtil.h"

Surface::Surface() {
}

Surface::Surface(SDL_Surface *surface) {
	this->surface = SDL_ConvertSurface(surface, surface->format, SDL_SWSURFACE);
}

Surface::Surface(Surface *surface, const Dimension &dimension) {
	SDL_Surface *x = surface->toSDL();
	this->surface = SDL_CreateRGBSurface((x)->flags | SDL_SRCALPHA, dimension.getWidth(),
			dimension.getHeight(), (x)->format->BitsPerPixel, (x)->format->Rmask, (x)->format->Gmask, (x)->format->Bmask, (x)->format->Amask);
}

Surface::Surface(const char *path, bool hasAlphaChannel) {
	load(path, hasAlphaChannel);
}

void Surface::load(const char *path, bool hasAlphaChannel) {
	SDL_Surface *normal = IMG_Load(path);
	if (!normal)
		throw runtime_error(IMG_GetError());

	SDL_Surface *optimized = (hasAlphaChannel ? SDL_DisplayFormatAlpha(normal)
			: SDL_DisplayFormat(normal));
	if (optimized != NULL) {
		SDL_FreeSurface(normal);
		surface = optimized;
	} else {
		surface = normal;
	}
}

Surface::~Surface() {
	if (surface) {
		SDL_FreeSurface(surface);
		surface = NULL;
	}
}

void Surface::optimize() {
	SDL_Surface *optimized = SDL_DisplayFormat(surface);
	if (optimized != NULL) {
		SDL_FreeSurface(surface);
		surface = optimized;
	}
}

Dimension Surface::getDimension() const {
	return Dimension(surface->w, surface->h);
}

void Surface::clean() {
	Uint32 a = SDL_MapRGB(surface->format, 200, 200, 200);
	SDL_FillRect(surface, NULL, a);
}

void Surface::clean(const Color &color) {
	Uint32 a = SDL_MapRGB(surface->format, color.getRed(), color.getGreen(),
			color.getBlue() );
	SDL_FillRect(surface, NULL, a);
}

void Surface::setTransparentColor(const Color &color) {
	Uint32 key = SDL_MapRGB(surface->format, color.getRed(), color.getGreen(),
			color.getBlue());
	SDL_SetColorKey(surface, SDL_SRCCOLORKEY | SDL_RLEACCEL, key);
}

void Surface::drawSurface(Surface *image, const Point &point) {
	SDL_Surface *imageSurf = image->toSDL();
	if(imageSurf == NULL) return;

	SDL_Rect rectDst = { point.getX(), point.getY(), 0, 0 };
	SDL_Rect rectSrc;

	rectSrc.x = rectSrc.y = 0;
	rectSrc.w = imageSurf->w;
	rectSrc.h = imageSurf->h;

	SDL_BlitSurface(imageSurf, &rectSrc, surface, &rectDst);
}

void Surface::updateArea(const Point &point, const Dimension &dimension) {
	SDL_UpdateRect(surface, point.getX(), point.getY(), dimension.getWidth(),
			dimension.getHeight());
}

void Surface::updateArea(const Area &area) {
	updateArea(area.getPoint(), area.getDimension());
}

void Surface::flip() {
	SDL_Flip(surface);
}

Surface * Surface::getArea(const Point & point, const Dimension & dimension) {
	SDL_Surface * area = SDL_CreateRGBSurface((surface)->flags | SDL_SRCALPHA, (dimension.getWidth()),
			(dimension.getHeight()), (surface)->format->BitsPerPixel, (surface)->format->Rmask, (surface)->format->Gmask, (surface)->format->Bmask, (surface)->format->Amask);
	SDL_Rect rect = { point.getX(), point.getY(), dimension.getWidth(),
			dimension.getHeight() };
	SDL_BlitSurface(surface, &rect, area, NULL);

	Surface * surface= new Surface(area);

	return surface;
}

Surface * Surface::getArea(const Area & area) {
	return getArea(area.getPoint(), area.getDimension());
}

void Surface::setOpacity(Uint8 opacity) {
	SDL_SetAlpha(surface, SDL_RLEACCEL | SDL_SRCALPHA, opacity);
}

SDL_Surface *Surface::toSDL() {
	return surface;
}
