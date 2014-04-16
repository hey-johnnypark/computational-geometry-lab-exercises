//============================================================================
// Name        : Aufg2.cpp
// Author      : 
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================
using namespace std;

#include <iostream>
#include "AreaCounter.h"
#include "Point.h"

int main() {
	Point a(12,12);
	Point b(100,928);
	Point c(22,299);
	Point d(38,1);
	Point e(29,933);
	Point f(12,11);
	Point g(122,113);
	std::vector<Point> ver;
	ver.push_back(a);
	ver.push_back(b);
	ver.push_back(c);
	ver.push_back(d);
	ver.push_back(e);
//	ver.push_back(f);
	//ver.push_back(g);
	AreaCounter counte(ver);
	float floater = counte.calculateArea();





	cout << "Gesamt: " << floater << endl; // prints
	return 0;
}
