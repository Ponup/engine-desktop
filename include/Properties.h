#ifndef PROPERTIES_H
#define PROPERTIES_H

#define LINE_SIZE 256

#include <string>
using std::string;

#include <map>
using std::pair;
using std::map;

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

#endif
