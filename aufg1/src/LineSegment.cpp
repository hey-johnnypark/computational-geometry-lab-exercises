/*
 * LineSegment.cpp
 *
 *  Created on: Apr 3, 2014
 *      Author: johnnypark
 */

#include "LineSegment.h"

LineSegment::LineSegment(const LineSegment &other) :
		a(other.a), b(other.b) {
}
;

LineSegment::LineSegment(Point a, Point b) :
		a(a), b(b) {
}
;

const Point& LineSegment::getA() const {
	return a;
}

const Point& LineSegment::getB() const {
	return b;
}

bool LineSegment::cuts(LineSegment* other) {
	int test1 = ccw(a, b, other->getA()) * ccw(a, b, other->getB());
	int test2 = ccw(other->getA(), other->getB(), a) * ccw(other->getA(), other->getB(), b);
	return test1 <= 0 && test2 <= 0;
}

int LineSegment::ccw(Point a, Point b, Point c) {
	return (a.x * b.y - a.y * b.x)
				+ (b.x * c.y - b.y * c.x)
				+ (a.y * c.x - a.x * c.y);
}

std::ostream& operator<<(std::ostream &strm, const LineSegment &a) {
	return strm << "LineSegment(" << a.getA() << ", " << a.getB() << ")";
}

std::ostream& operator<<(std::ostream &strm, const LineSegment* a) {
	return strm << "LineSegment(" << a->getA() << ", " << a->getB() << ")";
}


