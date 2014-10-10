#pragma once

#include "Font.h"

#include <map>
using std::map;

typedef map<char*, Font*> FontMap;

class FontManager {

	static FontMap fontMap;

public:
	static Font* getFont(const char *name, unsigned int size);
	static void destroy();
};

