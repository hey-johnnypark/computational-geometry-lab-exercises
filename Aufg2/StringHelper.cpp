/*
 * StringHelper.cpp
 *
 *  Created on: Apr 7, 2014
 *      Author: johnnypark
 */

#include "StringHelper.h"
#include <string>
#include <vector>

vector<string> StringHelper::split(string text, char delimiter) {
	vector<string> splittedValues;
	bool moreParts = true;
	while (moreParts) {
		if (text.find(delimiter) == string::npos) {
			splittedValues.push_back(text);
			moreParts = false;
		} else {
			string part = text.substr(0, text.find_first_of(delimiter));
			splittedValues.push_back(part);
			text = text.substr(text.find_first_of(delimiter) + 1, text.size());
		}
	}
	return splittedValues;
}
