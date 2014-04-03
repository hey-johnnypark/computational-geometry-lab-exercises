/*
 * Triangle.h
 *
 *  Created on: Apr 3, 2014
 *      Author: johnnypark
 */

#include "Point.h"

#ifndef TRIANGLE_H_
#define TRIANGLE_H_

class Triangle {
private:
	Point a,b,c;
public:
	Triangle(Point a, Point b, Point c);
	virtual ~Triangle();

	int ccw();

	const Point& getA() const {
		return a;
	}

	const Point& getB() const {
		return b;
	}

	const Point& getC() const {
		return c;
	}
};

#endif /* TRIANGLE_H_ */
