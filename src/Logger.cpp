#include "Logger.h"

Logger::Logger(const char *path) {
	fd = fopen(path, "a");
}

Logger::~Logger() {
	if(fd) fclose(fd);
	fd = NULL;
}

void Logger::log(const char *level, const char *message) {
	fprintf(fd, "%s: %s\n", level, message);
	fflush(fd);
}

