/*
 * LineSegment.cpp
 *
 *  Created on: Apr 3, 2014
 *      Author: johnnypark
 */

#include "LineSegment.h"
#include "Triangle.h"

LineSegment::LineSegment(Point a, Point b) {
	this->a = a;
	this->b = b;
}

const Point& LineSegment::getA() const {
	return a;
}

const Point& LineSegment::getB() const {
	return b;
}

bool LineSegment::cuts(LineSegment other) {
	int test1 = Triangle(a, b, other.getA()).ccw()
			* Triangle(a, b, other.getB()).ccw();
	int test2 = Triangle(other.getA(), other.getB(), a).ccw()
			* Triangle(other.getA(), other.getB(), b).ccw();
	return test1 <= 0 && test2 <= 0;
}

LineSegment::~LineSegment() {
}

