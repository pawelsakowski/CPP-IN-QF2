#include <iostream>
#include "simple_mc7.h"
#include "vanilla3.h"
#include "statistics_mc.h"

using namespace std;

int main()
{

    double expiry = 0.5;
    double strike = 100.0;
    double spot = 95.0;
    double vol = 0.2;
    double r = 0.06;
    unsigned long number_of_paths = 1000000;

    cout << "Do you want to enter your own option paramters (1) or use defaults (2)?\n";
    int choice;
    cin >> choice;

    if (choice == 1)
    {
        cout << "\nEnter expiry\n";
        cin >> expiry;

        cout << "\nEnter strike\n";
        cin >> strike;

        cout << "\nEnter spot\n";
        cin >> spot;

        cout << "\nEnter vol\n";
        cin >> vol;

        cout << "\nEnter r\n";
        cin >> r;

        cout << "\nEnter number of paths\n";
        cin >> number_of_paths;
    }

    PayOffCall thePayOff(strike);
    VanillaOption theOption(thePayOff, expiry);
    ParametersConstant volParam(vol);
    ParametersConstant rParam(r);
    StatisticsMean gatherer;

    simple_monte_carlo7(theOption,
                        spot,
                        volParam,
                        rParam,
                        number_of_paths,
                        gatherer);

    vector<vector<double>> results = gatherer.get_results_so_far();

    cout << "\nFor the call price the results are \n";

    for (unsigned long i = 0; i < results.size(); i++)
    {
        for (unsigned long j = 0; j < results[i].size(); j++)
        {
            cout << results[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
