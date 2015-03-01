#include "FontService.h"

#include <SDL_ttf.h>

#include <cstdio>

void FontService::init() {
	if(TTF_Init() == -1) {
		fprintf(stderr, "%s\n", TTF_GetError());
	}	
}

void FontService::destroy() {
	TTF_Quit();
}
