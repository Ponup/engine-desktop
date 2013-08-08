#ifndef SENSITIVE_AREAS_H
#define SENSITIVE_AREAS_H

#include <vector>
using std::vector;

#include "Area.h"
#include "Point.h"
#include "Dimension.h"

class SensitiveAreas {
	private:
		vector<Area> areas;

	public:
		void addArea(const Area & area);		
		void addArea(const Point & point, const Dimension & dimension);
		int resolve(int x, int y) const;
};

#endif
