#ifndef CORESERVICE_H
#define CORESERVICE_H

#include <SDL.h>

#include "Service.h"

/**
 * This service initializes the SDL library.
 * 
 * @see Service 
 */
class CoreService : public Service {
	
private:
	Uint32 flags;

public:
	const static int TIMER= SDL_INIT_TIMER;
	const static int AUDIO= SDL_INIT_AUDIO;
	const static int VIDEO= SDL_INIT_VIDEO;
	const static int CDROM= SDL_INIT_CDROM;
	const static int JOYSTICK= SDL_INIT_JOYSTICK;
	const static int EVERYTHING= SDL_INIT_EVERYTHING;
	const static int NOPARACHUTE= SDL_INIT_NOPARACHUTE;
	const static int EVENTTHREAD= SDL_INIT_EVENTTHREAD;

	CoreService(long flags = SDL_INIT_EVERYTHING);
	void init();
	void destroy();
};

#endif
