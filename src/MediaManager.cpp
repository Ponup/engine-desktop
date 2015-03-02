#include "MediaManager.h"

MediaManager * MediaManager::singleton = NULL;
map<const char *, MediaSound *> MediaManager::sounds;

MediaManager &MediaManager::getInstance() {
	if(!singleton) {
		singleton = new MediaManager();
	}
	
	return *singleton;
}
		
void MediaManager::playSound(const char *name) {
	SoundsMap::const_iterator it;
	it = sounds.find(name);
	if(it == sounds.end()) {
		char path[50];
		sprintf(path, "resources/sounds/%s", name);
		MediaSound *mediaSound = new MediaSound(path);
		mediaSound->play();

		sounds[name] = mediaSound;
	} else {
		MediaSound *mediaSound = it->second;
		mediaSound->play();
	}
}
