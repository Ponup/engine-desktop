#ifndef STRINGUTIL_H
#define STRINGUTIL_H

#include <vector>
using std::vector;

#include <string>
using std::string;

class StringUtil {

public:
	static char *trim(char *string);
	static char *strndup(const char *source, size_t len);
	static void tokenize(const string & str, vector<string> & tokens, const char *delim);
};

#endif
