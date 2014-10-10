#pragma once

#include <SDL.h>

class EventHandler {
	
private:
	SDL_Event event;

public:
	void captureEvents();

protected:
	virtual void onQuit(SDL_QuitEvent);
	virtual void onMouseMotion(SDL_MouseMotionEvent) = 0;
	virtual void onMouseButtonDown(SDL_MouseButtonEvent) = 0;
	virtual void onMouseButtonUp(SDL_MouseButtonEvent) = 0;
	virtual void onKeyDown(SDL_KeyboardEvent) = 0;
	virtual void onKeyUp(SDL_KeyboardEvent) = 0;
};

