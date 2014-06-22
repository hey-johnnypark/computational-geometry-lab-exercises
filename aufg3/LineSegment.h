/*
 * LineSegment.h
 *
 *  Created on: Apr 3, 2014
 *      Author: johnnypark
 */
#ifndef LINESEGMENT_H_
#define LINESEGMENT_H_

#include "Point.h"
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <string>
#include <stdio.h>

class LineSegment {
private:
	Point a, b;
	int ccw(Point* a, Point* b, Point* c);
public:
	LineSegment(Point a, Point b);
	LineSegment(const LineSegment& other);
	bool cuts(LineSegment* otherLineSegment);
	Point* getA();
	Point* getB();
};

namespace std {
namespace tr1 {

template<>
struct hash<LineSegment> {
	std::size_t operator()(LineSegment & l) const {
		return hash<Point>()(l.getA()) ^ hash<Point>()(l.getB());
	}
};
}
}

std::ostream& operator<<(std::ostream &strm, const LineSegment &a);
std::ostream& operator<<(std::ostream &strm, const LineSegment* a);

#endif /* LINESEGMENT_H_ */
