/*
 * Point.cpp
 *
 *  Created on: Apr 3, 2014
 *      Author: johnnypark
 */

#include "Point.h"

#include <iostream>

Point::~Point() {

}

std::ostream& operator<<(std::ostream &strm, const Point &a) {
	return strm << "P(" << a.x << "," << a.y << ")";
}
