#include "MediaSound.h"

#include <stdexcept>
using std::runtime_error;

#include <stdio.h>
#include <SDL.h>

MediaSound::MediaSound() {
	sound = NULL;
}

MediaSound::MediaSound(const char *name) {
	load(name);
}

MediaSound::~MediaSound() {
	if(sound)
		Mix_FreeChunk(sound);
}

void MediaSound::load(const char *name) {
	sound = Mix_LoadWAV(name);
	if(!sound) {
		fprintf(stderr, "%s\n", Mix_GetError());
		throw std::runtime_error(Mix_GetError());
	}
}

void MediaSound::play() {
	if(Mix_PlayChannel(-1, sound, 0) == -1) {
		fprintf(stderr, "%s\n", Mix_GetError());
	}
}

void MediaSound::setVolume(int volume) {
	// MIX_MAX_VOLUME
	Mix_VolumeChunk(sound, volume);
}

Mix_Chunk *MediaSound::toSDL() {
	return sound;
}

