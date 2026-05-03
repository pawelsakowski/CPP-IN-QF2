// ExoticBSEngine.cpp

#include <cmath>
#include "exotic_bs_engine.h"

// definition of the abstract class
void ExoticBSEngine::get_one_path(MJArray &spot_values)
{

    the_generator->get_gaussians(variates);

    double current_log_spot = log_spot;

    for (unsigned long j = 0; j < number_of_times; j++)
    {
        current_log_spot += drifts[j];
        current_log_spot += standard_deviations[j] * variates[j];
        spot_values[j] = exp(current_log_spot);
    }

    return;
}

// the constructor does relatively a lot of job!
// it precomputes as much as possible (according to Black and Scholes framework)
// before the doSimulation() method is called.
ExoticBSEngine::ExoticBSEngine(const Wrapper<PathDependent> &the_product_,
                               const Parameters &r_,
                               const Parameters &d_,
                               const Parameters &vol_,
                               const Wrapper<RandomBase> &the_generator_,
                               double spot_)
    : ExoticEngine(the_product_, r_),
      the_generator(the_generator_)
{
    MJArray times(the_product_->get_look_at_times());
    number_of_times = times.size();

    the_generator->reset_dimensionality(number_of_times);

    drifts.resize(number_of_times);
    standard_deviations.resize(number_of_times);

    double variance = vol_.get_integral_square(0, times[0]);

    drifts[0] = r_.get_integral(0.0, times[0]) - d_.get_integral(0.0, times[0]) - 0.5 * variance;
    standard_deviations[0] = sqrt(variance);

    for (unsigned long j = 1; j < number_of_times; ++j)
    {
        double this_variance = vol_.get_integral_square(times[j - 1], times[j]);
        drifts[j] = r_.get_integral(times[j - 1], times[j]) - d_.get_integral(times[j - 1], times[j]) - 0.5 * this_variance;
        standard_deviations[j] = sqrt(this_variance);
    }

    log_spot = log(spot_);
    variates.resize(number_of_times);
}
