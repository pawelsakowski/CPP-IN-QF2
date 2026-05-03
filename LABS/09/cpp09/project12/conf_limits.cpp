#include "statistics_mc.h"
#include "conf_limits.h"
#include "helpers.h"
#include <cmath>

using namespace std;

ConfidenceLimits::ConfidenceLimits()
    : payoffs(0.0)
{
}

void ConfidenceLimits::dump_one_result(double result)
{
    payoffs.push_back(result);
}

vector<vector<double>> ConfidenceLimits::get_results_so_far() const
{
    vector<vector<double>> Results(3);

    // increase size
    Results[0].resize(1);
    Results[0][0] = get_vec_mean(payoffs);
    Results[1].resize(1);
    Results[1][0] = get_vec_stddev(payoffs) / pow(payoffs.size(), 0.5);
    Results[2].resize(2);
    Results[2][0] = Results[0][0] - 1.96 * Results[1][0];
    Results[2][1] = Results[0][0] + 1.96 * Results[1][0];
    return Results;
}

StatisticsMC *ConfidenceLimits::clone() const
{
    return new ConfidenceLimits(*this);
}

void ConfidenceLimits::reset()
{
    payoffs.clear();
}
