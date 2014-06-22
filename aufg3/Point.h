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

namespace std {
template<>
struct hash<Point> {
	std::size_t operator()(Point & c) const {
		return hash<double>()(c.x) ^ hash<double>()(c.y);
	}
	std::size_t operator()(Point* c) const {
		return hash<double>()(c->x) ^ hash<double>()(c->y);
	}

};
}

std::ostream& operator<<(std::ostream &strm, const Point &a);

#endif /* POINT_H_ */
