#include "MixerService.h"

#include <stdio.h>
#include <SDL_mixer.h>

MixerService::MixerService() : frequency(MIX_DEFAULT_FREQUENCY), channels(2) {
}

MixerService::MixerService(int frequency_, int channels_) : frequency(frequency_), channels(channels_) {
}

void MixerService::init() {
	if(Mix_OpenAudio(frequency, MIX_DEFAULT_FORMAT, channels, 2048) == -1) {
		fprintf(stderr, "%s\n", Mix_GetError());
	}	
}

void MixerService::destroy() {
	Mix_CloseAudio();
}

