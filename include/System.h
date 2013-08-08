#ifndef SYSTEM_H
#define SYSTEM_H

#include <SDL.h>

class System {

	public:
		static void delay(int ms);
		static void waitUser();
		static void showCursor(bool visible);
		static void setMousePosition(int x, int y);
		static void setKeyRepeat(int delay = SDL_DEFAULT_REPEAT_DELAY, int interval = SDL_DEFAULT_REPEAT_INTERVAL);
};

#endif
