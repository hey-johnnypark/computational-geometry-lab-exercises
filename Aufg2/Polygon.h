/*
 * Polygon.h
 *
 *  Created on: 27.05.2014
 *      Author: Mox
 */

#ifndef POLYGON_H_
#define POLYGON_H_
#include <vector>
#include "Point.h"
using namespace std;

class Polygon{
	std::vector<Point> points;

public:
	Polygon(std::vector<Point> points);
	virtual ~Polygon();

	std::vector<Point> getPoints() const {
		return points;
	}
	int pip(Point point) const;

	bool pointInPolygon(Point point);
	int ccw(Point a, Point b, Point c);
	int sgn(int x);
};




#endif /* POLYGON_H_ */
