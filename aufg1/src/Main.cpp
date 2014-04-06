#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include "StringHelper.h"

//#include "LineSegment.h"
//#include "Point.h"
//#include "Triangle.h"

using namespace std;

int main(int argc, char **argv) {

	double lol = atof("10.29");

	vector<string> parts = StringHelper::split("hallo,wie,gehts", ',');

	for (string part : parts) {
		cout << part;
	}

	string line;
	string del = " ";
	ifstream infile;
	infile.open("resources/Strecken_1000.txt");
	while (true) // To get you all the lines.
	{
		getline(infile, line);
		if (line != "") {
			string first;
			string rest;
			first = line.substr(0, line.find_first_of(" "));
			rest = line.substr(line.find_first_of(" ") + 1, line.size());
			//cout << "First: " << first << endl;
			//cout << "Rest: " << "#" << rest << "#" << endl;
		} else {
			break;
		}

	}
	infile.close();

}

