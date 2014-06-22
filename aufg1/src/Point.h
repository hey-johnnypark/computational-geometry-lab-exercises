/*
 * Point.h
 *
 *  Created on: Apr 3, 2014
 *      Author: johnnypark
 */

#ifndef POINT_H_
#define POINT_H_

#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <string>
#include <stdio.h>

class Point {
public:
	const double x, y;
	Point(double x, double y) :
			x(x), y(y) {
	}
	;
	virtual ~Point();
};

std::ostream& operator<<(std::ostream &strm, const Point &a);

namespace std {
template<>
struct std::hash<Point> {
	size_t operator()(const Point & p) const {
		return hash<double>()(p.x) ^ hash<double>()(p.y);;
	}
};
}

#endif /* POINT_H_ */
