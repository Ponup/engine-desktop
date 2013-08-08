#include "FontService.h"

#include <SDL_ttf.h>

void FontService::init() {
	if(TTF_Init() == -1) {
		fprintf(stderr, "%s\n", TTF_GetError());
	}	
}

void FontService::destroy() {
	TTF_Quit();
}
