/*
 * Point.h
 *
 *  Created on: 15.04.2014
 *      Author: Mox
 */

#ifndef POINT_H_
#define POINT_H_

class Point {
	float x,y;
public:
	Point(float x, float y);
	virtual ~Point();

	float getX() const{
		return x;
	}
	float getY() const {
		return y;
	}

};

#endif /* POINT_H_ */
