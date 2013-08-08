#include "Properties.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <stdexcept>
using std::runtime_error;

#include "StringUtil.h"

Properties::Properties() {
}

Properties::~Properties() {
}

void Properties::load(const char *fileName) {
	this->fileName = fileName;

	FILE *file = fopen(fileName, "r");	
	if(!file) {
		char msg[100];
		memset(msg, '\0', 100);
		sprintf(msg, "File '%s' not found.", fileName);
		throw runtime_error(msg);
	}
	
	properties.clear();

	char *lineFile = (char *)malloc(sizeof(char) * 121);
	memset(lineFile, '\0', 121);

	while((lineFile = fgets(lineFile, 121, file)) != NULL) {
		char *line = StringUtil::trim(lineFile);
		if(strlen(line) == 0) continue;
		if(line[0] == '#') continue;

		char *pos = strchr(line, '=');
		if(!pos)
			continue;

		int position = (pos - line);

		char *key = StringUtil::strndup(line, position);
		char *value = StringUtil::strndup(line + position + 1, strlen(line) - position);

		properties.insert(KeyValue(key, value));
		free(line);
		memset(lineFile, '\0', 121);
	}

	free(lineFile);
	fclose(file);
}

void Properties::save(const char *fileName) {
	if(!fileName) fileName = this->fileName;

	FILE *file = fopen(fileName, "w+");
	if(!file)
		return;

	size_t charSize = sizeof(char);

	StringsMap::const_iterator it;
	for(it = properties.begin(); it != properties.end(); it++) {
		const char *key = it->first.c_str();
		const char *value = it->second.c_str();

		fwrite(key, charSize, strlen(key), file);
		fwrite("=", charSize, 1, file);
		fwrite(value, charSize, strlen(value), file);
		fwrite("\n", charSize, 1, file);
	}
	
	fclose(file);
}

const char *Properties::getProperty(const char *propertyName) const {
	StringsMap::const_iterator it;
	it = properties.find(propertyName);
	if(it == properties.end()) {
		return NULL;
	} else {
		return it->second.c_str();
	}
}

void Properties::setProperty(string propertyName, string propertyValue) {
	StringsMap::const_iterator it;
	it = properties.find(propertyName);
	properties.erase(it->first);
	properties.insert(KeyValue(propertyName, propertyValue));
}

bool Properties::getBoolProperty(const char * propertyName) const {
	const char *p = getProperty(propertyName);
	
	return strncmp(p, "True", 4) == 0;
}

void Properties::setBoolProperty(string propertyName, bool propertyValue) {
	setProperty(propertyName, (propertyValue ? string("True") : string("False")));
}

