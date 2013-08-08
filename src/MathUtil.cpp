#include "MathUtil.h"

const float MathUtil::PI = 3.14159265;

float MathUtil::calculateDistance(const Point &a, const Point &b) {
	float adj = (b.getX() - a.getX());
	float opp = (b.getY() - a.getY());

	return sqrtf(adj * adj + opp * opp);
}

double MathUtil::calculateDegrees(const Point &a, const Point &b) {
	float adj = (b.getX() - a.getX());
	float opp = (b.getY() - a.getY());	

	return radian2degree(atan2(opp, adj));
}

vector<Point> MathUtil::calculatePath(const Point &a, const Point &b) {	
	float distance = calculateDistance(a, b);

	// We protect the min and max distance to not create an enourmous vector
	if(distance < 0)
		distance = 0;
	else if(distance > 256)
		distance = 256;

	vector<Point> points(distance);
	double degrees = calculateDegrees(a, b);
	for(unsigned int i = 0; i < distance; i++) {
		double radians = degree2radian(degrees);
		int x = int(i * cos(radians));
		int y = int(i * sin(radians));
		
		Point point(x, y);
		points.push_back(point);
	}
	
	return points;
}
