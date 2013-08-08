#ifndef MIXERSERVICE_H
#define MIXERSERVICE_H

#include "Service.h"

/**
 * This service initializes the SDL_mixer library.
 * 
 * @see Service 
 */
class MixerService : public Service {
	private:
		int frequency;
		int channels;
		
	public:
		MixerService();
		MixerService(int frequency, int channels);
		void init();
		void destroy();
};

#endif
