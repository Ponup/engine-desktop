#include "System.h"

void System::delay(int ms) {
	SDL_Delay(ms);
}

void System::waitUser() {
	SDL_Event event;
	bool quit = false;
	while(!quit) {
		while(SDL_PollEvent(&event)) {
			quit = (event.type == SDL_MOUSEBUTTONDOWN || event.type == SDL_KEYDOWN || event.type == SDL_QUIT);
		}
		SDL_Delay(10);		
	}
}

void System::showCursor(bool visible) {
	SDL_ShowCursor(visible ? 1 : 0);
}

void System::setMousePosition(int x, int y) {
	SDL_WarpMouse(x, y);
}

void System::setKeyRepeat(int delay, int interval) {
	SDL_EnableKeyRepeat(delay, interval);
}
