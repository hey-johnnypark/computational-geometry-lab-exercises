/*
 * AreaCounter.cpp
 *
 *  Created on: 15.04.2014
 *      Author: Mox
 */
using namespace std;
#include <iostream>
#include "AreaCounter.h"

AreaCounter::AreaCounter(std::vector<Point> vect) {
	this->vect = vect;
	start = 0;
	end = vect.size() - 1;
	area = 0;

}

AreaCounter::~AreaCounter() {
}

float AreaCounter::calculateArea() {
	if (start == end) {
		Point tempPointA = vect.at(start);
		Point tempPointB = vect.at(0);
		Point tempPointC = vect.at(start - 1);
		float tempArea = ((float) tempPointA.getY()
				* (tempPointC.getX() - tempPointB.getX())) / 2;

		//cout <<" A: " << tempPointA.getX() << " / " << tempPointA.getY() << " tempArea: " << tempArea << "\n";
		return tempArea;
	} else {

		Point tempPointA = vect.at(start);
		Point tempPointB = vect.at(start + 1);
		Point tempPointC(0, 0);
		if (start == 0) {
			tempPointC = vect.at(vect.size() - 1);
		} else {
			tempPointC = vect.at(start - 1);
		}
		//cout<< tempPointA.getX() <<"/"<< tempPointB.getY()<<endl;
		float tempArea = ((float) tempPointA.getY()
				* (tempPointC.getX() - tempPointB.getX())) / 2;
		//cout <<" A: " << tempPointA.getX() << " / " << tempPointA.getY() << " tempArea: " << tempArea << "\n";
		start++;
		return tempArea + calculateArea();

//		float tempArea = (tempPointB.getY() + tempPointA.getX() - tempPointA.getY()*tempPointB.getX()) / 2;
//		area = area + tempArea;
//		cout <<" A: " << tempPointA.getX() << tempPointA.getY() << " tempArea: " << tempArea << " Area: " << area << "\n";
//		start++;
//		return tempArea + calculateArea(area);
	}
}
float AreaCounter::calculateArea_2() {
	float area = 0;

	for (unsigned int i = 1; i < vect.size(); i++) {

		if (i == vect.size() - 1) {
			area += vect.at(i).getY()
					* ((vect.at(i - 1).getX() - vect.at(0).getX()) / 2);
		} else {
			float tmpArea = vect.at(i).getY()
					* ((vect.at(i - 1).getX() - vect.at(i + 1).getX()) / 2);
			area += vect.at(i).getY()
					* ((vect.at(i - 1).getX() - vect.at(i + 1).getX()) / 2);
		}
	}
	return area;
}

