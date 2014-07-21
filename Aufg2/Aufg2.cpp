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
#include "City.h"

const float area_factor = 1.17103781508;

void calculate(string currentBundesland, float realArea) {
	std::vector<Point> points;
	std::vector<Polygon> polygons;
	std::vector<City> cities;
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
	infile.open("resrc/City.txt");

	while (true) // To get you all the lines.
	{
		getline(infile, line);
		if(line != ""){
			vector<string> lineParts = StringHelper::split(line, ';');
			string id = lineParts[0].c_str();
			float p1 = atof(lineParts[1].c_str());
			float p2 = atof(lineParts[2].c_str());
			City city = City(id, p1, p2);
			//cout << city.getId() << " x: "<<city.getX() << " y: " << city.getY() << endl;
			cities.push_back(city);


		}else{
			break;

		}


	}

	infile.close();



	float totalArea = 0;
	std::string cityName;
	for (unsigned int i = 0; i < polygons.size(); i++) {
		AreaCounter counter(polygons.at(i).getPoints());
		float floater2 = counter.calculateArea_2();
		totalArea = totalArea + floater2;
		//cout << polygons.at(i).pointInPolygon(Point(499.89102,405.76395)) << endl;
		for(unsigned int j = 0; j < cities.size(); j++){
			if(polygons.at(i).pointInPolygon(Point(cities.at(j).getX(),cities.at(j).getY())) == 1){
				cityName = cities.at(j).getId();
				break;
			}
		}
	}

	cout << currentBundesland << ":  " << totalArea * area_factor << "( Poly: "
			<< polygons.size() << ") " << "Real-Area: " << realArea
			<< " square km" <<  " Stadt: " << cityName << endl;
}

int main() {

	calculate("resrc/Bayern.txt", 70550.11);
	calculate("resrc/Saarland.txt", 2568.75);
	calculate("resrc/badenWuertenberg.txt", 35751.48);
	calculate("resrc/Berlin.txt", 887.70);
	calculate("resrc/Brandenburg.txt", 29483.13);
	calculate("resrc/Bremen.txt", 419.24);
	calculate("resrc/Hamburg.txt", 755.16);
	calculate("resrc/Hessen.txt", 21114.91);
	calculate("resrc/MeckPommern.txt", 23190.76);
	calculate("resrc/Niedersachsen.txt", 47612.88);
	calculate("resrc/NordrheinWestfalen.txt", 34092.25);
	calculate("resrc/ReinlandPfalz.txt", 19854.06);
	calculate("resrc/Sachsen.txt", 18419.71);
	calculate("resrc/SachsenAnhalt.txt", 20449.54);
	calculate("resrc/Schleswig-Holstein.txt", 15799.25);
	calculate("resrc/Thueringen.txt", 16172.50);

	cout << endl
			<< "Real Area Source: http://www.bernhard-gaul.de/wissen/bundeslaender.php"
			<< endl;

	return 0;
}

