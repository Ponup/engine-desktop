#ifndef MEDIASOUND_H
#define MEDIASOUND_H

#include <SDL_mixer.h>

class MediaSound {
	
	private:
		Mix_Chunk *sound;
		
	public:
		MediaSound();
		MediaSound(const char *name);
		~MediaSound();
		
		void load(const char *name);
		void play();
		void setVolume(int volume);
		Mix_Chunk* toSDL();
};

#endif
