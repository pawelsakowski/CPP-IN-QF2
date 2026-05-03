#ifndef CONF_LIMITS_H
#define CONF_LIMITS_H

#include "statistics_mc.h"
#include <vector>

class ConfidenceLimits : public StatisticsMC
{

public:
    ConfidenceLimits();
    virtual void dump_one_result(double result);
    virtual std::vector<std::vector<double>> get_results_so_far() const;
    virtual StatisticsMC *clone() const;
    virtual void reset();

private:
    std::vector<double> payoffs;
};

#endif
