// ExoticEngine.cpp

#include <cmath>
#include "exotic_engine.h"

// constructor
ExoticEngine::ExoticEngine(
    const Wrapper<PathDependent> &the_product_,
    const Parameters &r_)
    : the_product(the_product_),
      r(r_),
      discounts(the_product_->possible_cash_flow_times())
{
    // precomputations all discount factors
    for (unsigned long i = 0; i < discounts.size(); i++)
        discounts[i] = exp(-r.get_integral(0.0, discounts[i]));

    these_cash_flows.resize(the_product_->max_number_of_cash_flows());
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// a method for LOOPING!
void ExoticEngine::do_simulation(StatisticsMC &the_gatherer, unsigned long number_of_paths)
{
    MJArray spot_values(the_product->get_look_at_times().size());

    these_cash_flows.resize(the_product->max_number_of_cash_flows());
    double this_value;

    // this is main Monte Carlo loop
    for (unsigned long i = 0; i < number_of_paths; ++i)
    {
        get_one_path(spot_values);                // simulates the path (this method is abstract)
        this_value = do_one_path(spot_values);    // calculate the discounted cash flows
        the_gatherer.dump_one_result(this_value); // passes the discounted cash flows to the gatherer
    }

    return;
}

// a method for calculating discounted cash flows
double ExoticEngine::do_one_path(const MJArray &spot_values) const
{
    unsigned long number_flows = the_product->cash_flows(spot_values,
                                                         these_cash_flows);
    double value = 0.0;

    // discounting of cashflows (payoff or payoffs for a single path)
    // and summing them together
    for (unsigned long i = 0; i < number_flows; ++i)
        value += these_cash_flows[i].amount * discounts[these_cash_flows[i].time_index];

    return value;
}
