/*
 * LineSegment.cpp
 *
 *  Created on: Apr 3, 2014
 *      Author: johnnypark
 */

#include "LineSegment.h"

LineSegment::LineSegment(LineSegment &other) :
		a(other.a), b(other.b) {
}
;

LineSegment::LineSegment(Point a, Point b) :
		a(a), b(b) {
}
;

Point* LineSegment::getA() {
	return &a;
}

Point* LineSegment::getB() {
	return &b;
}

bool LineSegment::intersects(LineSegment* other) {
	int test1 = ccw(&a, &b, other->getA()) * ccw(&a, &b, other->getB());
	int test2 = ccw(other->getA(), other->getB(), &a)
			* ccw(other->getA(), other->getB(), &b);
	return test1 <= 0 && test2 <= 0;
}

int LineSegment::ccw(Point* a, Point* b, Point* c) {
	return (a->x * b->y - a->y * b->x) + (b->x * c->y - b->y * c->x)
			+ (a->y * c->x - a->x * c->y);
}

std::ostream& operator<<(std::ostream &strm, LineSegment &a) {
	return strm << "LineSegment(" << a.getA() << ", " << a.getB() << ")";
}

std::ostream& operator<<(std::ostream &strm, LineSegment* a) {
	return strm << "LineSegment(" << a->getA() << ", " << a->getB() << ")";
}

bool operator==(const LineSegment l1, const LineSegment l2) {
	return true;
}

