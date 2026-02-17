// simple_mc.cpp

#include "simple_mc.h"
#include "random1.h"
#include <cmath>

double simple_monte_carlo(const Payoff& the_payoff,
                          double expiry,
                          double spot,
                          double vol,
                          double r,
                          unsigned long number_of_paths)
{
	double variance = vol * vol * expiry;
	double root_variance = sqrt(variance);
	double ito_correction = -0.5 * variance;

	double moved_spot = spot * exp(r * expiry + ito_correction);
	double running_sum = 0;

	for (unsigned long i = 0; i < number_of_paths; i++)
	{
		double this_gaussian = get_one_gaussian_by_box_muller();
		double this_spot = moved_spot * exp(root_variance * this_gaussian);
		double this_payoff = the_payoff(this_spot);
		running_sum += this_payoff;
	}

	double mean = running_sum / number_of_paths;
	mean *= exp(-r * expiry);
	return mean;
}
