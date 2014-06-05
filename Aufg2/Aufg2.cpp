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
#include "Polygon.h"

void calculate(string currentBundesland) {
	std::vector<Point> points;
	std::vector<Polygon> polygons;
	string line;
	ifstream infile;
	infile.open(currentBundesland.c_str());
	Point relative_root(0, 0);
	while (true) // To get you all the lines.
	{
		getline(infile, line);
		if (line != "") {
			if (line.substr(0, 1) == "M") {
				points.clear();
				vector<string> lineParts = StringHelper::split(line, ',');
				float p1 = atof(
						lineParts[0].substr(1, lineParts[0].length()).c_str());
				float p2 = atof(lineParts[1].c_str());
				points.push_back(Point(p1, p2));
				relative_root = Point(p1, p2);
			} else if (line.substr(0, 1) == "l") {
				vector<string> lineParts = StringHelper::split(line, ',');
				float p1 = atof(
						lineParts[0].substr(1, lineParts[0].length()).c_str())
						+ relative_root.getX();
				float p2 = atof(lineParts[1].c_str()) + relative_root.getY();
				Point point = Point(p1, p2);
				relative_root = point;
				points.push_back(point);
			} else if (line.substr(0, 1) == "z") {
				polygons.push_back(Polygon(points));
			} else if (line.substr(0, 1) == "L") {
				vector<string> lineParts = StringHelper::split(line, ',');
				float p1 = atof(
						lineParts[0].substr(1, lineParts[0].length()).c_str());
				float p2 = atof(lineParts[1].c_str());
				Point lPoint = Point(p1, p2);
				points.push_back(lPoint);
				relative_root = lPoint;
			}

		} else {
			break;
		}

	}

	infile.close();
	float totalArea = 0;
	for (unsigned int i = 0; i < polygons.size(); i++) {
		AreaCounter counter(polygons.at(i).getPoints());
		float floater2 = counter.calculateArea_2();
		totalArea = totalArea + floater2;
	}

	cout << currentBundesland << ":  " << totalArea << "( Poly: "
			<< polygons.size() << ")" << endl;
}

int main() {

	calculate("resrc/Bayern.txt");
	calculate("resrc/Saarland.txt");
	calculate("resrc/badenWuertenberg.txt");
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
	calculate("resrc/Thueringen.txt");

	return 0;
}

