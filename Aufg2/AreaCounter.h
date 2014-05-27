/*
 * AreaCounter.h
 *
 *  Created on: 15.04.2014
 *      Author: Mox
 */

#ifndef AREACOUNTER_H_
#define AREACOUNTER_H_
#include "Point.h"
#include <vector>
using namespace std;

class AreaCounter {
	std::vector<Point> vect;
	int start;
	int end;
	int area;

public:
	AreaCounter(std::vector<Point>);
	virtual ~AreaCounter();
	float calculateArea();
	float calculateArea_2();
};

#endif /* AREACOUNTER_H_ */
