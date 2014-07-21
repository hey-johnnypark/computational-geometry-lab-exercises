/*
 * Point.h
 *
 *  Created on: 15.04.2014
 *      Author: Mox
 */

#ifndef POINT_H_
#define POINT_H_

class Point {

public:
	float x,y;
	Point(float x, float y);
	virtual ~Point();

	float getX() const{
		return x;
	}
	float getY() const {
		return y;
	}

	void setX(float x) {
		this->x = x;
	}

	void setY(float y) {
		this->y = y;
	}
};

#endif /* POINT_H_ */
