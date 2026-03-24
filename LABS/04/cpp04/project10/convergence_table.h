#ifndef CONVERGENCE_TABLE_H
#define CONVERGENCE_TABLE_H

#include "statistics_mc.h"
#include "wrapper.h"

class ConvergenceTable : public StatisticsMC
{
public:
    ConvergenceTable(const Wrapper<StatisticsMC> &Inner_);

    virtual StatisticsMC *clone() const;
    virtual void dump_one_result(double result);
    virtual std::vector<std::vector<double>> get_results_so_far() const;

private:
    Wrapper<StatisticsMC> Inner;
    std::vector<std::vector<double>> results_so_far;
    unsigned long stopping_point;
    unsigned long paths_done;
};

#endif
