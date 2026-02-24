// random1.cpp

#include "random1.h"
#include <cstdlib>
#include <cmath>

// definitions of functions
double get_one_gaussian_by_summation()
{
	double result = 0;

	for (unsigned long j = 0; j < 12; j++)
		result += rand() / static_cast<double>(RAND_MAX);

	result -= 6.0;
	return result;
}

double get_one_gaussian_by_box_muller()
{
	double x;
	double y;

	double size_squared;
	do
	{
		x = 2.0 * rand() / static_cast<double>(RAND_MAX) - 1;
		y = 2.0 * rand() / static_cast<double>(RAND_MAX) - 1;
		size_squared = x * x + y * y;
	} while (size_squared >= 1.0);

	double result = x * sqrt(-2 * log(size_squared) / size_squared);

	return result;
}
