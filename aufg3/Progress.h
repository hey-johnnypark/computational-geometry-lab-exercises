/*
 * Progress.h
 *
 *  Created on: Apr 24, 2014
 *      Author: johnnypark
 */

#ifndef PROGRESS_H_
#define PROGRESS_H_

class Progress {
private:
	long currentProgress;
	long lastPercentage;
	long total;
public:
	Progress(long total) :currentProgress(0), lastPercentage(0), total(total) {};
	void incrProgress();
	void incrProgress(int units);
};

#endif /* PROGRESS_H_ */
