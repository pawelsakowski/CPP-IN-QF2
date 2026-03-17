#include <cmath>
#include "simple_mc7.h"
#include "random1.h"

using namespace std;

void simple_monte_carlo7(const VanillaOption &the_option,
						 double spot,
						 const Parameters &vol,
						 const Parameters &r,
						 unsigned long number_of_paths,
						 StatisticsMC &gatherer)
{
	double expiry = the_option.get_expiry();
	double variance = vol.get_integral_square(0, expiry);
	double rootVariance = sqrt(variance);
	double itoCorrection = -0.5 * variance;
	double movedspot = spot * exp(r.get_integral(0, expiry) + itoCorrection);
	double thisspot;
	double discounting = exp(-r.get_integral(0, expiry));

	for (unsigned long i = 0; i < number_of_paths; i++)
	{
		double thisGaussian = get_one_gaussian_by_box_muller();
		thisspot = movedspot * exp(rootVariance * thisGaussian);
		double thisPayOff = the_option.get_option_payoff(thisspot);
		gatherer.dump_one_result(thisPayOff * discounting);
	}
}
