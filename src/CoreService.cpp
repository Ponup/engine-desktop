#include "CoreService.h"

#include <stdio.h>

CoreService::CoreService(long flags_) : flags(flags_) {
}

void CoreService::init() {
	if(SDL_Init(flags) == -1) {
		fprintf(stderr, "%s\n", SDL_GetError());
	}
	
	atexit(SDL_Quit);
}

void CoreService::destroy() {
	SDL_Quit();	
}
