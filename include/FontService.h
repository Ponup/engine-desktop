#pragma once

#include "Service.h"

/**
 * This service initializes the SDL_ttf library.
 * 
 * @see Service 
 */
class FontService : public Service {
	
public:
	void init();
	void destroy();
};

