#include "MathUtil.h"

float MathUtil::calculateDistance(const Point &a, const Point &b) {
	float adj = (b.x - a.x);
	float opp = (b.y - a.y);

	return sqrtf(adj * adj + opp * opp);
}

double MathUtil::calculateDegrees(const Point &a, const Point &b) {
	float adj = (b.x - a.x);
	float opp = (b.y - a.y);	

	return radian2degree(atan2(opp, adj));
}

vector<Point> MathUtil::calculatePath(const Point &a, const Point &b) {	
	vector<Point> points;

	float distance = calculateDistance(a, b);
	double degrees = calculateDegrees(a, b);

	for( unsigned int i = 0; i < distance; i++ ) {
		double radians = degree2radian( degrees );
		int x = int( i * cos(radians ) );
		int y = int( i * sin(radians ) );
		
		if( x != 0 || y != 0 )
		{
			Point point( x, y );
			points.push_back( point );
		}
	}
	
	return points;
}
