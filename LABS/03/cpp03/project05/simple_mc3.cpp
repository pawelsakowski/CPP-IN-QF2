#include "simple_mc3.h"
#include "random1.h"
#include <cmath>

using namespace std;

double SimpleMonteCarlo3(VanillaOption theOption,
						 double spot,
						 double vol,
						 double r,
						 unsigned long number_of_paths)
{

	double expiry = theOption.get_expiry();

	double variance = vol * vol * expiry;
	double rootVariance = sqrt(variance);
	double itoCorrection = -0.5 * variance;

	double movedspot = spot * exp(r * expiry + itoCorrection);
	double thisspot;
	double runningSum = 0;

	for (unsigned long i = 0; i < number_of_paths; i++)
	{
		double thisGaussian = get_one_gaussian_by_box_muller();
		thisspot = movedspot * exp(rootVariance * thisGaussian);
		double thisPayOff = theOption.get_option_payoff(thisspot);
		runningSum += thisPayOff;
	}

	double mean = runningSum / number_of_paths;
	mean *= exp(-r * expiry);
	return mean;
}
