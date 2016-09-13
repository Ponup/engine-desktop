#include "FileUtils.h"

#include <fstream>

bool Kangaroo::FileUtils::fileExists(const char* path) const {
	std::ifstream f(path);
	return f.is_open();
}