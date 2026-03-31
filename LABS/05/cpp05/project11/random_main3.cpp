#include <iostream>
#include "simple_mc8.h"
#include "park_miller.h"
#include "vanilla3.h"
#include "statistics_mc.h"
#include "convergence_table.h"
#include "conf_limits.h"
#include "antithetic.h"
#include "helpers.h"
#include <ctime>
#include <cstdlib>
#include <cmath>

using namespace std;

int main()
{
    srand(time(NULL));
    // unsigned long baseSeed = rand();
    unsigned long baseSeed = 123;

    double expiry = 0.5;
    double strike = 100;
    double spot = 95;
    double vol = 0.2;
    double r = 0.06;
    unsigned long number_of_paths = 1000000;
    unsigned int number_of_experiments = 100;

    PayOffCall the_payoff(strike);
    VanillaOption the_option(the_payoff, expiry);

    ParametersConstant VolParam(vol);
    ParametersConstant rParam(r);

    // ==================================================
    cout << "\nWe have the following parameters:\n";
    cout << "expiry           = " << expiry << "\n";
    cout << "strike           = " << strike << "\n";
    cout << "spot             = " << spot << "\n";
    cout << "vol              = " << vol << "\n";
    cout << "r                = " << r << "\n";
    cout << "number_of_paths  = " << number_of_paths << "\n";

    // ==================================================
    // pricing without antithetic variates
    ConfidenceLimits gatherer1;
    RandomParkMiller generator1(1);

    generator1.set_seed(124);
    gatherer1.reset();
    simple_monte_carlo8(the_option,
                        spot,
                        VolParam,
                        rParam,
                        number_of_paths,
                        gatherer1,
                        generator1);
    vector<vector<double>> result = gatherer1.get_results_so_far();

    cout << "\nFor the call price the results are: \n";
    print_results(result);

    return 0;
}
