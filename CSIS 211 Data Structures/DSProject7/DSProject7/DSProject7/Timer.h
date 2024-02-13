/*
Timer.h
John Barbonio (auth. by Glenn Stevenson)
7/16/2020
: This timer seems to work based on the CPU frequency of the computer
*/

#pragma once

#include <windows.h>

class Timer
{
private:
	LARGE_INTEGER start;
	LARGE_INTEGER stop;
	LARGE_INTEGER freq;
	double PCFreq;
	__int64 CounterStart;

public:
	Timer();
	void startTimer();
	void stopTimer();
	double getMilli();
	double getSeconds();
	double getMicro();

};