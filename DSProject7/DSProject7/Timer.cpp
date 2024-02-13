/*
Timer.cpp
John Barbonio
7/16/2020
: This timer cpp class defines the functions of Timer.h, is used 
*/

#include <iostream>
#include "Timer.h"

using std::cout;
using std::endl;

/*
Function: Timer constructor
Author: John Barbonio
Date: 7/18/2020
Desc: Constructor grabs CPU frequency from PC for timing
I: n/a
O: n/a
*/
Timer::Timer()
{
	if (!QueryPerformanceFrequency(&freq))
		cout << "QueryPerformanceFrequency failed!\n";

}
/*
Function: startTimer
Author: John Barbonio
Date: 7/18/2020
Desc: starts query timing CPU
I: n/a
O: n/a
*/
void Timer::startTimer()
{

	QueryPerformanceCounter(&start);


}
/*
Function: startTimer
Author: John Barbonio
Date: 7/18/2020
Desc: ends query timing CPU and process between start and end
I: n/a
O: n/a
*/
void Timer::stopTimer()
{
	QueryPerformanceCounter(&stop);

}
/*
Function: getMicro
Author: John Barbonio
Date: 7/18/2020
Desc: gets microseconds from query length
I: n/a
O: n/a
*/
double Timer::getMicro()
{
	PCFreq = freq.QuadPart / 1000000.0;
	return double((stop.QuadPart - start.QuadPart)) / PCFreq;
}
/*
Function: getMicro
Author: John Barbonio
Date: 7/18/2020
Desc: gets milliseconds from query length
I: n/a
O: n/a
*/
double Timer::getMilli()
{
	PCFreq = freq.QuadPart / 1000.0;
	return double((stop.QuadPart - start.QuadPart)) / PCFreq;
}
/*
Function: getMicro
Author: John Barbonio
Date: 7/18/2020
Desc: gets seconds from query length
I: n/a
O: n/a
*/
double Timer::getSeconds()
{
	return double(stop.QuadPart - start.QuadPart) / freq.QuadPart;
}