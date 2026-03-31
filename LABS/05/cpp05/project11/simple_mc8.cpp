#include <cmath>
#include "simple_mc8.h"
#include "arrays.h"
#include <iostream>

using namespace std;

void simple_monte_carlo8(const VanillaOption &the_option,
						 double spot,
						 const Parameters &vol,
						 const Parameters &r,
						 unsigned long number_of_paths,
						 StatisticsMC &gatherer,
						 RandomBase &generator)
{
	generator.reset_dimensionality(1);

	double expiry = the_option.get_expiry();
	double variance = vol.get_integral_square(0, expiry);
	double root_variance = sqrt(variance);
	double ito_correction = -0.5 * variance;
	double moved_spot = spot * exp(r.get_integral(0, expiry) + ito_correction);

	double this_spot;
	double discounting = exp(-r.get_integral(0, expiry));

	MJArray VariateArray(1);

	for (unsigned long i = 0; i < number_of_paths; i++)
	{
		generator.get_gaussians(VariateArray);
		this_spot = moved_spot * exp(root_variance * VariateArray[0]);
		// cout << "this VariateArray[0] is " << VariateArray[0] << "\n";
		double this_payoff = the_option.get_option_payoff(this_spot);
		gatherer.dump_one_result(this_payoff * discounting);
	}
}
