#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <map>
#include "StringHelper.h"
#include "LineSegment.h"
#include "Point.h"

//#include "Triangle.h"

using namespace std;

int main(int argc, char **argv) {

	vector<LineSegment> lineSegments;
	string line;
	ifstream infile;
	infile.open("resources/Strecken_1000.txt");
	while (true) // To get you all the lines.
	{
		getline(infile, line);
		if (line != "") {
			vector<string> lineParts = StringHelper::split(line, ' ');
			double p1 = atof(lineParts[0].c_str());
			double p2 = atof(lineParts[1].c_str());
			double p3 = atof(lineParts[2].c_str());
			double p4 = atof(lineParts[3].c_str());
			lineSegments.push_back(LineSegment(Point(p1, p2), Point(p3, p4)));
		} else {
			break;
		}

	}
	infile.close();

	cout << "Total lines: " << lineSegments.size();

	int cuttedLines = 0;

	for (LineSegment segment : lineSegments) {
		for (LineSegment otherSegment : lineSegments) {
			if (segment.cuts(otherSegment)) {
				cuttedLines++;
			}
		}
	}

	cout << "Total: " << cuttedLines;

}

