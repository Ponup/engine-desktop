#ifndef MATHUTIL_H
#define MATHUTIL_H

#include <math.h>

#include <vector>
using std::vector;

#include "Point.h"

class MathUtil {
	
public:
	static const float PI;

	static inline float degree2radian(float degree) {
		return (degree * PI/180);
	}

	static inline float radian2degree(float radian) {
		return (radian * 180/PI);
	}

	static float calculateDistance(const Point &a, const Point &b);
	static double calculateDegrees(const Point &a, const Point &b);
	static vector<Point> calculatePath(const Point &a, const Point &b);
};

#endif
