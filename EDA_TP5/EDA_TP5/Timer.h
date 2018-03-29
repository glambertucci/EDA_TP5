#pragma once
#include <chrono>

using namespace std::chrono;
#define TIMERERROR (-1)

class Timer
{
public:
	Timer();
	~Timer();
	void start();
	void stop();
	float getTime(); // In ms
private:
	high_resolution_clock::time_point  startValue;
	bool getStartValue;
	high_resolution_clock::time_point  stopValue;
	bool getStopValue;
	duration<float> timePassed;
};

