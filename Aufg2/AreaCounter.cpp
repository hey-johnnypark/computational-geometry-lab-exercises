/*
 * AreaCounter.cpp
 *
 *  Created on: 15.04.2014
 *      Author: Mox
 */
using namespace std;
#include <iostream>
#include "AreaCounter.h"

AreaCounter::AreaCounter( std::vector<Point> vect) {
	this->vect = vect;
	start = 0;
	end = vect.size() - 1;
	area = 0;

}

AreaCounter::~AreaCounter() {
}

float AreaCounter::calculateArea(){
	if(start == end){
		Point tempPointA = vect.at(start);
		Point tempPointB = vect.at(0);
		Point tempPointC = vect.at(start - 1);
		float tempArea = ((float)tempPointA.getY() * ( tempPointC.getX() - tempPointB.getX())) / 2;

		//cout <<" A: " << tempPointA.getX() << " / " << tempPointA.getY() << " tempArea: " << tempArea << "\n";
		return tempArea;
	} else {


		Point tempPointA = vect.at(start);
		Point tempPointB = vect.at(start + 1);
		Point tempPointC(0,0);
		if(start == 0){
			tempPointC = vect.at(vect.size()-1);
		} else {
			tempPointC = vect.at(start - 1);
		}
		//cout<< tempPointA.getX() <<"/"<< tempPointB.getY()<<endl;
		float tempArea = ((float)tempPointA.getY() * ( tempPointC.getX() - tempPointB.getX())) / 2;
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
	float AreaCounter::calculateArea_2(){
		float area = 0;

		 for(unsigned int i = 0;i <= vect.size() - 1; i++){
			 Point tempPointA = vect.at(i);
			 Point tempPointB = vect.at(i == vect.size()-1 ? 0 : i+1);
			 Point tempPointC = vect.at(i == 0 ? vect.size()-1 : i-1 );


			 area = area +  ((float)tempPointA.getY() * ( (float)tempPointC.getX() - (float)tempPointB.getX())) / 2;
			// area = area + ((float)tempPointA.getY() + tempPointB.getY()) / 2 * (tempPointA.getX() - tempPointB.getX());
			// cout << " X: " << tempPointA.getX() << " Y: " << tempPointA.getY() << " Area : " << area<< " tempArea: " << ((float)tempPointA.getY() + tempPointB.getY()) / 2 * (tempPointA.getX() - tempPointB.getX()) << endl;
		 }
		 return area;
		 //Bayern : 60.000
	 }



