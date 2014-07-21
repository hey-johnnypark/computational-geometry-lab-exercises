/*
 * City.h
 *
 *  Created on: 21.07.2014
 *      Author: Mox
 */

#ifndef CITY_H_
#define CITY_H_
#include <string>
#include <iostream>

class City {
private:
	float x,y;
	std::string id;
public:
	City(std::string id, float x, float y);
	virtual ~City();

	float getX() const{
		return x;
	}
	float getY() const {
		return y;
	}

	void setX(float x) {
		this->x = x;
	}

	void setY(float y) {
		this->y = y;
	}

	const std::string& getId() const {
		return id;
	}

	void setId(const std::string& id) {
		this->id = id;
	}
};



#endif /* CITY_H_ */
