#include "convergence_table.h"

// constructor
ConvergenceTable::ConvergenceTable(const Wrapper<StatisticsMC> &Inner_) : Inner(Inner_)
{
    stopping_point = 2;
    paths_done = 0;
}

// definition of clone() method
StatisticsMC *ConvergenceTable::clone() const
{
    return new ConvergenceTable(*this);
}

void ConvergenceTable::dump_one_result(double result)
{
    Inner->dump_one_result(result);
    ++paths_done;

    if (paths_done == stopping_point)
    {
        stopping_point *= 2;
        std::vector<std::vector<double>> this_result(Inner->get_results_so_far());

        for (unsigned long i = 0; i < this_result.size(); i++)
        {
            this_result[i].push_back(paths_done);
            results_so_far.push_back(this_result[i]);
        }
    }
}

std::vector<std::vector<double>> ConvergenceTable::get_results_so_far() const
{
    std::vector<std::vector<double>> result(results_so_far);

    if (paths_done * 2 != stopping_point)
    {
        std::vector<std::vector<double>> this_result(Inner->get_results_so_far());

        for (unsigned long i = 0; i < this_result.size(); i++)
        {
            this_result[i].push_back(paths_done);
            result.push_back(this_result[i]);
        }
    }
    return result;
}

void ConvergenceTable::reset()
{
    Inner->reset();
    stopping_point = 2;
    paths_done = 0UL;
}
