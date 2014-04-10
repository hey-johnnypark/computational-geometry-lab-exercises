/*
 * Point.h
 *
 *  Created on: Apr 3, 2014
 *      Author: johnnypark
 */

#ifndef POINT_H_
#define POINT_H_

#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <string>
#include <stdio.h>


class Point {
private:
	double x, y;
public:
	Point();
	Point(double x, double y);
	virtual ~Point();
	double getX() const;
	double getY() const;
};

std::ostream& operator<<(std::ostream &strm, const Point &a);

#endif /* POINT_H_ */
