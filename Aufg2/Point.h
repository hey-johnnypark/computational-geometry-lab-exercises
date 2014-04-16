/*
 * Point.h
 *
 *  Created on: 15.04.2014
 *      Author: Mox
 */

#ifndef POINT_H_
#define POINT_H_

class Point {
	int x,y;
public:
	Point(int x, int y);
	virtual ~Point();

	int getX() const{
		return x;
	}
	int getY() const {
		return y;
	}

};

#endif /* POINT_H_ */
