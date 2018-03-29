#include "Timer.h"



Timer::Timer()
{
	this->getStartValue = false;
	this->getStopValue = false;

}


Timer::~Timer()
{
}

void Timer::start()
{
	this->startValue = high_resolution_clock::now();
	this->getStartValue = true;
}

void Timer::stop()
{
	this->stopValue = high_resolution_clock::now();
	this->getStopValue = true;
}

float Timer::getTime()
{
	float retValue = TIMERERROR;
	if (this->getStartValue && this->getStopValue)
	{
		this->timePassed = this->stopValue - this->startValue;
		retValue = this->timePassed.count();
	}
	return retValue;
}
