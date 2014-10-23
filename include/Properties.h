#pragma once

#define LINE_SIZE 256

#include <utility>
using std::pair;

#include <map>
using std::map;

#include <string>
using std::string;

class Properties {

private:
	typedef pair<string, string> KeyValue;
	typedef map<string, string> StringsMap;
	
	StringsMap properties;

	const char *fileName;

public:
	Properties();
	virtual ~Properties();
				
	void load(const char *fileName);
	void save(const char *fileName = NULL);
	
	const char *getProperty(const char *propertyName) const;
	void setProperty(const string propertyName, string propertyValue);
	
	bool getBoolProperty(const char *propertyName) const;
	void setBoolProperty(const string propertyName, bool propertyValue);
};

