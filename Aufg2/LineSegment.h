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
	int ccw(Point* a, Point* b, Point* c);
public:
	Point a, b;
	LineSegment(Point a, Point b);
	LineSegment(LineSegment& other);
	bool cuts(LineSegment* otherLineSegment);
	Point* getA();
	Point* getB();
};

std::ostream& operator<<(std::ostream &strm, const LineSegment &a);
std::ostream& operator<<(std::ostream &strm, const LineSegment* a);

namespace std {

}

#endif /* LINESEGMENT_H_ */
