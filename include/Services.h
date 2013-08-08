#ifndef SERVICES_H
#define SERVICES_H

#include <vector>
using std::vector;

#include "Service.h"

class Services {
	private:
		vector<Service *> services;
		
	public:
		void addService(Service * service);
		void init();
		void destroy();	
};

#endif
