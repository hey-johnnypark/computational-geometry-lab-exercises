/*
 * Point.cpp
 *
 *  Created on: Apr 3, 2014
 *      Author: johnnypark
 */

#include "Point.h"

#include <iostream>

Point::Point() {
	this->x = 0;
	this->y = 0;
}

Point::Point(double x, double y) {
	this->x = x;
	this->y = y;
}

double Point::getX() const {
	return x;
}

double Point::getY() const {
	return y;
}

Point::~Point() {

}

std::ostream& operator<<(std::ostream &strm, const Point &a) {
	return strm << "P(" << a.getX() << "," << a.getX() << ")";
}
