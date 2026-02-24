#include "simple_mc2.h"
#include "random1.h"
#include <cmath>

double simple_monte_carlo2(const PayOff &payOff,
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
    double thisspot;
    double running_sum = 0;

    for (unsigned long i = 0; i < number_of_paths; i++)
    {
        double this_gaussian = get_one_gaussian_by_box_muller();
        thisspot = moved_spot * exp(root_variance * this_gaussian);
        double this_payOff = payOff(thisspot);
        running_sum += this_payOff;
    }

    double mean = running_sum / number_of_paths;
    mean *= exp(-r * expiry);
    return mean;
}
