/*
 * City.cpp
 *
 *  Created on: 21.07.2014
 *      Author: Mox
 */


#include "City.h"
#include <string>

City::City(std::string id,float x, float y) {
	this->x = x;
	this->y = y;
	this->id = id;

}

City::~City() {

}

