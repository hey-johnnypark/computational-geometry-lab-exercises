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
public:
	LineSegment(Point a, Point b);
	LineSegment(const LineSegment& other);
	bool cuts(LineSegment otherLineSegment);
	const Point& getA() const;
	const Point& getB() const;
};

std::ostream& operator<<(std::ostream &strm, const LineSegment &a);

#endif /* LINESEGMENT_H_ */
