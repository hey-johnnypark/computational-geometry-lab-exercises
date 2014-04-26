/*
 * StringHelper.h
 *
 *  Created on: Apr 7, 2014
 *      Author: johnnypark
 */

#include <string>
#include <vector>

#ifndef STRINGHELPER_H_
#define STRINGHELPER_H_

using namespace std;

class StringHelper {
public:
	static vector<string> split(string text, char delimiter);

};

#endif /* STRINGHELPER_H_ */
