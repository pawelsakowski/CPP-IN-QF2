#ifndef EXOTIC_ENGINE_H
#define EXOTIC_ENGINE_H

#include <vector>
#include "wrapper.h"
#include "parameters.h"
#include "path_dependent.h"
#include "statistics_mc.h"

class ExoticEngine
{
public:
    ExoticEngine(const Wrapper<PathDependent> &the_product_,
                 const Parameters &r_);

    // abstract method!
    virtual void get_one_path(MJArray &spot_values) = 0;

    void do_simulation(StatisticsMC &the_gatherer, unsigned long number_of_paths);
    virtual ~ExoticEngine() {}
    double do_one_path(const MJArray &spot_values) const;

private:
    Wrapper<PathDependent> the_product;
    Parameters r;
    MJArray discounts;
    mutable std::vector<CashFlow> these_cash_flows;
};

#endif
