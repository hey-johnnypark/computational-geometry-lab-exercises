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
#include <cstdlib>
#include <fstream>
#include <iostream>
#include "StringHelper.h"

void calculate(string currentBundesland){
			std::vector<Point> points;
			string line;
			ifstream infile;
			infile.open(currentBundesland.c_str());

			while (true) // To get you all the lines.
			{
				getline(infile, line);
				if (line != "") {
					vector<string> lineParts = StringHelper::split(line, ',');
					float p1 = atof(lineParts[0].c_str());
					float p2 = atof(lineParts[1].c_str());
					points.push_back(Point(p1,p2));
				} else {
					break;
				}

			}

			infile.close();
			AreaCounter counter(points);
			float floater2 = counter.calculateArea();

			cout << currentBundesland<<":  " <<floater2 << endl; // prints

}




int main() {
//	Point a(12.5,12.4);
//	Point b(124.4,124.32);
//	Point c(123.3,21.1);
//	Point d(38,1);
//	Point e(29,933);
//	Point f(12,11);
//	Point g(122,113);
//	std::vector<Point> ver;
//	ver.push_back(a);
//	ver.push_back(b);
//	ver.push_back(c);
////	ver.push_back(d);
////	ver.push_back(e);
////	ver.push_back(f);
//	//ver.push_back(g);
//	AreaCounter counte(ver);
//	float floater = counte.calculateArea();

	calculate("resrc/Saarland.txt");
	calculate("resrc/badenWürttenbergg.txt");
	calculate("resrc/Bayern.txt");
	calculate("resrc/Berlin.txt");
	calculate("resrc/Brandenburg.txt");
	calculate("resrc/Bremen.txt");
	calculate("resrc/Hamburg.txt");
	calculate("resrc/Hessen.txt");
	calculate("resrc/MeckPommern.txt");
	calculate("resrc/Niedersachsen.txt");
	calculate("resrc/NordrheinWestfalen.txt");
	calculate("resrc/ReinlandPfalz.txt");
	calculate("resrc/Sachsen.txt");
	calculate("resrc/SachsenAnhalt.txt");
	calculate("resrc/Schleswig-Holstein.txt");
	calculate("resrc/Thüringen.txt");




	return 0;
}

