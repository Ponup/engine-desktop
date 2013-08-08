#ifndef LOGGER_H
#define LOGGER_H

#include <stdio.h>

class Logger {

	FILE *fd;

public:
	Logger(const char *path);
	~Logger();

	void log(const char *level, const char *message);
};

#endif

