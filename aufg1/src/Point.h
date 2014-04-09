/*
 * Point.h
 *
 *  Created on: Apr 3, 2014
 *      Author: johnnypark
 */

#ifndef POINT_H_
#define POINT_H_

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

#endif /* POINT_H_ */
