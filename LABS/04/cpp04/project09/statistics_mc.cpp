#include "statistics_mc.h"
using namespace std;

StatisticsMean::StatisticsMean() : running_sum(0.0), paths_done(0UL)
{
}

void StatisticsMean::dump_one_result(double result)
{
    paths_done++;
    running_sum += result;
}

vector<vector<double>> StatisticsMean::get_results_so_far() const
{
    vector<vector<double>> Results(1);

    Results[0].resize(1);
    Results[0][0] = running_sum / paths_done;

    return Results;
}

StatisticsMC *StatisticsMean::clone() const
{
    return new StatisticsMean(*this);
}
