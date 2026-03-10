#include "iostream"
#include "simple_mc4.h"
#include "vanilla2.h"
using namespace std;

int main()
{
    double expiry;
    double strike;
    double spot;
    double vol;
    double r;
    unsigned long number_of_paths;

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

    cout << "\nNumber of paths\n";
    cin >> number_of_paths;

    PayOffCall the_payoff(strike);
    VanillaOption option1(the_payoff, expiry);
    double result = simple_monte_carlo4(option1,
                                        spot,
                                        vol,
                                        r,
                                        number_of_paths);
    cout << "\nthe call price is " << result << "\n";

    VanillaOption option2(option1);
    result = simple_monte_carlo4(option2,
                                 spot,
                                 vol,
                                 r,
                                 number_of_paths);
    cout << "\nthe call price is " << result << "\n";

    PayOffPut the_payoff2(strike);
    VanillaOption option3(the_payoff2, expiry);
    option1 = option3;
    result = simple_monte_carlo4(option1,
                                 spot,
                                 vol,
                                 r,
                                 number_of_paths);
    cout << "\nthe put price is " << result << "\n";

    return 0;
}
