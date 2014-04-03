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
	float x,y;
public:
	Point();
	Point(float x, float y);
	virtual ~Point();
	float getX() const;
	float getY() const;
};

#endif /* POINT_H_ */
