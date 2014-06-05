/*
 * Progress.cpp
 *
 *  Created on: Apr 24, 2014
 *      Author: johnnypark
 */

#include "Progress.h"
#include <stdlib.h>
#include  <iostream>
#include <stdio.h>

using namespace std;

void Progress::incrProgress() {
	this->incrProgress(1);
}

void Progress::incrProgress(int units) {
	this->currentProgress += units;
	int percentage = (int) (this->currentProgress / (double) this->total * 100);
//	cout << this->currentProgress << " # " << this->total << " # " << percentage
	//		<< endl;
	if (percentage % 5 == 0 && percentage != 0
			&& percentage != this->lastPercentage) {
		cout << "Progress " << percentage << "% (" << currentProgress << "/"
				<< total << ")" << endl;
		this->lastPercentage = percentage;
	}

}

