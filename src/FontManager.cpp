#include "FontManager.h"

FontMap FontManager::fontMap = FontMap();

Font* FontManager::getFont(const char *name, unsigned int size) {
	char temp[100];
	memset(temp, '\0', 100);
	sprintf(temp, "%s_%d", name, size);
	char *key = strdup(temp);

	FontMap::iterator it;
	it = fontMap.find(temp);

	if(it != fontMap.end())
		return (*it).second;

	memset(temp, '\0', 100);
	sprintf(temp, "resources/fonts/%s.ttf", name);
	Font *font = new Font(temp, size);

	fontMap.insert(FontMap::value_type(key, font));

	return font;
}

void FontManager::destroy() {
	FontMap::iterator it;
	for(it = fontMap.begin(); it != fontMap.end(); it++) {
		free((*it).first);
		delete (*it).second;
	}
	fontMap.clear();
}
