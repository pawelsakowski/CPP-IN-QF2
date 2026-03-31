#ifndef STATISTICS_MC_H
#define STATISTICS_MC_H

#include <vector>

class StatisticsMC
{
public:
    StatisticsMC() {};
    virtual void dump_one_result(double result) = 0;
    virtual std::vector<std::vector<double>> get_results_so_far() const = 0;
    virtual StatisticsMC *clone() const = 0;
    virtual ~StatisticsMC() {};
    virtual void reset() = 0;

private:
};

class StatisticsMean : public StatisticsMC
{

public:
    StatisticsMean();
    virtual void dump_one_result(double result);
    virtual std::vector<std::vector<double>> get_results_so_far() const;
    virtual StatisticsMC *clone() const;
    virtual void reset();

private:
    double running_sum;
    unsigned long paths_done;
};

#endif
