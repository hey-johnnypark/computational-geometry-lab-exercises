/*
 * LineSegment.h
 *
 *  Created on: Apr 3, 2014
 *      Author: johnnypark
 */

#include "Point.h"

#ifndef LINESEGMENT_H_
#define LINESEGMENT_H_

class LineSegment {
private:
	Point a,b;
public:
	LineSegment(Point a, Point b);
	virtual ~LineSegment();
	bool cuts(LineSegment otherLineSegment);
	const Point& getA() const;
	const Point& getB() const;
};

#endif /* LINESEGMENT_H_ */
