/*
 * Triangle.cpp
 *
 *  Created on: Apr 3, 2014
 *      Author: johnnypark
 */

#include "Triangle.h"
#include "Point.h"

Triangle::Triangle(Point a, Point b, Point c) {
	this->a = a;
	this->b = b;
	this->c = c;
}

int Triangle::ccw() {
	return (a.getX() * b.getY() - a.getY() * b.getX())
			+ (b.getX() * c.getY() - b.getY() * c.getX())
			+ (a.getY() * c.getX() - a.getX() * c.getY());
}

Triangle::~Triangle() {
}

