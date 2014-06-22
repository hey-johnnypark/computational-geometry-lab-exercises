#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <map>
#include <unordered_set>
#include "StringHelper.h"
#include "LineSegment.h"
#include "Point.h"
#include "Progress.h"
#include "Main.h"
#include <time.h>
#include <ctime>
//#include "Triangle.h"

using namespace std;

int main(int argc, char **argv) {

	Point point = Point(1.2, 1.4);
//	cout << hash<Point>()(point);

	LineSegment line = LineSegment(point, Point(1, 1));
//cout << hash<LineSegment>()(line);

	unordered_set<LineSegment> set;
	cout << set.size();
	set.insert(line);
//	bench("resources/Strecken_1000.txt");
//	bench("resources/Strecken_10000.txt");
	//bench("resources/Strecken_100000.txt");

}

void bench(string file) {
	time_t start = time(NULL) * 1000;
	cout << "Starting benchmark for file [" << file << "] at " << start << endl;
	vector<LineSegment*> lineSegments;
	string line;
	ifstream infile;
	infile.open("resources/Strecken_10000.txt");
	while (true) // To get you all the lines.
	{
		getline(infile, line);
		if (line != "") {
			vector<string> lineParts = StringHelper::split(line, ' ');
			double p1 = atof(lineParts[0].c_str());
			double p2 = atof(lineParts[1].c_str());
			double p3 = atof(lineParts[2].c_str());
			double p4 = atof(lineParts[3].c_str());
			lineSegments.push_back(
					new LineSegment(Point(p1, p2), Point(p3, p4)));
		} else {
			break;
		}

	}
	infile.close();
	cout << "Read " << lineSegments.size() << " line segments from [" << file
			<< "] at " << time(NULL) * 1000 << endl;

	int interval_start = 1;
	int num_segments = lineSegments.size();
	int num_cuts = 0;
	Progress progress = Progress(lineSegments.size());

	LineSegment* segment = 0;
	for (unsigned int i = 0; i < lineSegments.size(); i++) {
		segment = lineSegments.at(i);
		for (int current = interval_start; current < num_segments; current++) {
			LineSegment* segmentToCompare = lineSegments[current];
			if (segment->cuts(segmentToCompare)) {
				num_cuts++;
			}
		}
		interval_start++;
		progress.incrProgress();
	}

	cout << "# of cuts between line segments: " << num_cuts << endl;

	long duration = time(NULL) * 1000 - start;
	cout << "Total time needed: " << duration << "ms" << endl << endl;

}

