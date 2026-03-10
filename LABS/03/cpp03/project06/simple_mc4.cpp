#include "simple_mc4.h"
#include "random1.h"
#include <cmath>

using namespace std;

double simple_monte_carlo4(const VanillaOption &the_option,
						   double spot,
						   double vol,
						   double r,
						   unsigned long number_of_paths)
{

	double expiry = the_option.get_expiry();

	double variance = vol * vol * expiry;
	double root_variance = sqrt(variance);
	double ito_correction = -0.5 * variance;

	double moved_spot = spot * exp(r * expiry + ito_correction);
	double this_spot;
	double running_sum = 0;

	for (unsigned long i = 0; i < number_of_paths; i++)
	{
		double this_gaussian = get_one_gaussian_by_box_muller();
		this_spot = moved_spot * exp(root_variance * this_gaussian);
		double thisPayOff = the_option.get_option_payoff(this_spot);
		running_sum += thisPayOff;
	}

	double mean = running_sum / number_of_paths;
	mean *= exp(-r * expiry);
	return mean;
}
