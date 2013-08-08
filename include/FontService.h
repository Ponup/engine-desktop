#ifndef FONTSERVICE_H
#define FONTSERVICE_H

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

#endif
