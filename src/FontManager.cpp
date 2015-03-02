#include "FontManager.h"

FontMap FontManager::fontMap = FontMap();

Font* FontManager::getFont( const string& name, unsigned int size ) {
	char temp[100];
	memset(temp, '\0', 100);
	sprintf(temp, "%s_%d", name.c_str(), size);
	string fontKey(temp);

	FontMap::iterator it;
	it = fontMap.find(temp);

	if(it != fontMap.end()) {
		return (*it).second;
	}

	memset(temp, '\0', 100);
	sprintf(temp, "resources/fonts/%s.ttf", name.c_str() );
	Font *font = new Font(temp, size);

	fontMap.insert(FontMap::value_type(fontKey, font));

	return font;
}

void FontManager::destroy() {
	FontMap::iterator it;
	for(it = fontMap.begin(); it != fontMap.end(); it++) {
		delete (*it).second;
	}
	fontMap.clear();
}

