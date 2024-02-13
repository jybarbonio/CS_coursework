#include <vector>
#include "Integer.h"
#include "Double.h"

using std::vector;

#ifndef RANDOM
#define RANDOM

class Random 
{
private:
	vector<double> data;
public:
	Random();
	Random(double min, double max);
	Random(Double min, Double max);
	Random(int seed);

	int nextInt();
	Integer nextInteger();
	double nextDbl();
	Double nextDouble();
	void setRange(double min, double max);
	void setRange(Double min, Double max);
};

#endif
